#include "../Header/CLevel.h"

#include <cstdlib>
#include <iostream>

using namespace std;

CLevel::CLevel(Level _lev) {
	levelLabel.setFont(localFont->getInstance()->SemiBold);
	levelLabel.setCharacterSize(60);
	levelLabel.setFillColor(sf::Color::White);

	this->setLevel(_lev);
}

float CLevel::getDistance() {
	int i = rand();

	switch (this->lev) {
	case Level::Level_1: return 350.0f + i % 400;
	case Level::Level_2: return 300.0f + i % 400;
	case Level::Level_3: return 250.0f + i % 400;
	case Level::Level_4: return 200.0f + i % 400;
	case Level::Level_5: return 200.0f + i % 300;
	default: return 0.0f;
	}
}

float CLevel::getPeopleStep() {
	switch (this->lev) {
	case Level::Level_1: return 2.0f;
	case Level::Level_2: return 2.25f;
	case Level::Level_3: return 2.5f;
	case Level::Level_4: return 2.75f;
	case Level::Level_5: return 3.0f;
	default: return 0.0f;
	}
}

float CLevel::getCarStep() {
	switch (this->lev) {
	case Level::Level_1: return 0.00015f;
	case Level::Level_2: return 0.0003f;
	case Level::Level_3: return 0.0006f;
	case Level::Level_4: return 0.001f;
	case Level::Level_5: return 0.0014f;
	default: return 0.0f;
	}
}

float CLevel::getTruckStep()
{
	switch (this->lev) {
	case Level::Level_1: return -0.00017f;
	case Level::Level_2: return -0.00034f;
	case Level::Level_3: return -0.00068f;
	case Level::Level_4: return -0.0012f;
	case Level::Level_5: return -0.0015f;
	default: return 0.0f;
	}
}

float CLevel::getBirdStep() {
	switch (this->lev) {
	case Level::Level_1: return -0.0001f;
	case Level::Level_2: return -0.0002f;
	case Level::Level_3: return -0.0004f;
	case Level::Level_4: return -0.0008f;
	case Level::Level_5: return -0.0012f;
	default: return 0.0f;
	}
}

float CLevel::getDinausorStep() {
	switch (this->lev) {
	case Level::Level_1: return 0.00013f;
	case Level::Level_2: return 0.00026f;
	case Level::Level_3: return 0.00052f;
	case Level::Level_4: return 0.00104f;
	case Level::Level_5: return 0.0011f;
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
	}
	sf::FloatRect textRect = this->levelLabel.getLocalBounds();
	this->levelLabel.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	this->levelLabel.setPosition(sf::Vector2f(170, 340));
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
	case Level::Level_5:
		return false;
	}
	return true;
}