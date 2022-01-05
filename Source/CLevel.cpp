#include "../Header/CLevel.h"

#include <cstdlib>
#include <iostream>

using namespace std;

CLevel::CLevel(Level _lev) {
	levelLabel.setFont(localFont->getInstance()->ArialRounded);
	levelLabel.setCharacterSize(60);
	levelLabel.setFillColor(sf::Color::White);

	this->setLevel(_lev);
}

float CLevel::getDistance() {
	int i = rand();

	switch (this->lev) {
	case Level::Level_1: return 400.0f + i % 300;
	case Level::Level_2: return 350.0f + i % 300;
	case Level::Level_3: return 300.0f + i % 300;
	case Level::Level_4: return 250.0f + i % 300;
	case Level::Level_5: return 230.0f + i % 300;
	case Level::Level_6: return 210.0f + i % 250;
	case Level::Level_7: return 190.0f + i % 200;
	default: return 0.0f;
	}
}

float CLevel::getPeopleStep() {
	switch (this->lev) {
	case Level::Level_1: return 2.0f;
	case Level::Level_2: return 2.3f;
	case Level::Level_3: return 2.6f;
	case Level::Level_4: return 2.9f;
	case Level::Level_5: return 3.2f;
	case Level::Level_6: return 3.5f;
	case Level::Level_7: return 3.8f;
	default: return 0.0f;
	}
}

float CLevel::getCarStep() {
	switch (this->lev) {
	case Level::Level_1: return 0.0002f;
	case Level::Level_2: return 0.0003f;
	case Level::Level_3: return 0.0005f;
	case Level::Level_4: return 0.00045f;
	case Level::Level_5: return 0.0007f;
	case Level::Level_6: return 0.00065f;
	case Level::Level_7: return 0.00085f;
	default: return 0.0f;
	}
}

float CLevel::getTruckStep() {
	switch (this->lev) {
	case Level::Level_1: return -0.00022f;
	case Level::Level_2: return -0.00033f;
	case Level::Level_3: return -0.00055f;
	case Level::Level_4: return -0.00050f;
	case Level::Level_5: return -0.00077f;
	case Level::Level_6: return -0.00070f;
	case Level::Level_7: return -0.00090f;
	default: return 0.0f;
	}
}

float CLevel::getBirdStep() {
	switch (this->lev) {
	case Level::Level_1: return -0.0001f;
	case Level::Level_2: return -0.0002f;
	case Level::Level_3: return -0.0004f;
	case Level::Level_4: return -0.00035f;
	case Level::Level_5: return -0.0006f;
	case Level::Level_6: return -0.00055f;
	case Level::Level_7: return -0.00075f;
	default: return 0.0f;
	}
}

float CLevel::getDinausorStep() {
	switch (this->lev) {
	case Level::Level_1: return 0.00015f;
	case Level::Level_2: return 0.00025f;
	case Level::Level_3: return 0.00045f;
	case Level::Level_4: return 0.00040f;
	case Level::Level_5: return 0.00065f;
	case Level::Level_6: return 0.00060f;
	case Level::Level_7: return 0.0008f;
	default: return 0.0f;
	}
}

bool CLevel::isActiveTrafficLight() {
	switch (this->lev) {
	case Level::Level_1: 
	case Level::Level_2: return false;
	case Level::Level_3: return true;
	case Level::Level_4: return false;
	case Level::Level_5: return true;
	case Level::Level_6: return false;
	case Level::Level_7: return true;
	default: return 0.0f;
	}
}

void CLevel::drawLevelLabel(sf::RenderWindow& window) { window.draw(this->levelLabel); }

string CLevel::getLevel() { return this->levelLabel.getString(); }

void CLevel::setLevel(Level _lev) {
	switch (_lev) {
	case Level::Level_1:
		this->lev = Level::Level_1;
		this->levelLabel.setString("Level 1");
		break;
	case Level::Level_2:
		this->lev = Level::Level_2;
		this->levelLabel.setString("LEVEL 2");
		break;
	case Level::Level_3:
		this->lev = Level::Level_3;
		this->levelLabel.setString("LEVEL 3");
		break;
	case Level::Level_4:
		this->lev = Level::Level_4;
		this->levelLabel.setString("LEVEL 4");
		break;
	case Level::Level_5:
		this->lev = Level::Level_5;
		this->levelLabel.setString("LEVEL 5");
		break;
	case Level::Level_6:
		this->lev = Level::Level_4;
		this->levelLabel.setString("LEVEL 6");
		break;
	case Level::Level_7:
		this->lev = Level::Level_5;
		this->levelLabel.setString("LEVEL 7");
		break;
	}
	sf::FloatRect textRect = this->levelLabel.getLocalBounds();
	this->levelLabel.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	this->levelLabel.setPosition(sf::Vector2f(170, 380));
}

void CLevel::loadLevel(std::string str) {
	char _lev = str[str.length() - 1];
	switch (_lev) {
	case '1':
		this->setLevel(Level::Level_1);
		break;
	case '2':
		this->setLevel(Level::Level_2);
		break;
	case '3':
		this->setLevel(Level::Level_3);
		break;
	case '4':
		this->setLevel(Level::Level_4);
		break;
	case '5':
		this->setLevel(Level::Level_5);
		break;
	case '6':
		this->setLevel(Level::Level_6);
		break;
	case '7':
		this->setLevel(Level::Level_7);
		break;
	default:
		cout << "Wrong level !!" << endl;
		break;
	}
}

bool CLevel::upLevel() {
	cout << "Level up" << endl;
	switch (this->lev) {
	case Level::Level_1:
		this->setLevel(Level::Level_2);
		break;
	case Level::Level_2:
		this->setLevel(Level::Level_3);;
		break;
	case Level::Level_3:
		this->setLevel(Level::Level_4);
		break;
	case Level::Level_4:
		this->setLevel(Level::Level_5);
		break;
	case Level::Level_5:
		this->setLevel(Level::Level_6);
		break;
	case Level::Level_6:
		this->setLevel(Level::Level_7);
		break;
	case Level::Level_7:
		return false;
	}
	return true;
}