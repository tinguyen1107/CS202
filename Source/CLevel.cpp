#include "../Header/CLevel.h"

#include <cstdlib>
#include <iostream>

using namespace std;

CLevel::CLevel(Level _lev) {
	levelLabel.setFont(localFont.SemiBold);
	levelLabel.setCharacterSize(60);
	levelLabel.setFillColor(sf::Color::White);
	levelLabel.setPosition(0, 0);

	this->setLevel(_lev);
}

float CLevel::getDistance() {
	int i = rand();

	switch (this->lev) {
	case Level::Level_1:
		return 250.0f + i % 400;
	case Level::Level_2:
		return 200.0f + i % 400;
	case Level::Level_3:
		return 150.0f + i % 400;
	case Level::Level_4:
		return 122.0f + i % 400;
	case Level::Level_5:
		return 122.0f + i % 300;
	}
}

float CLevel::getCarStep() {
	switch (this->lev) {
	case Level::Level_1:
		return 0.0002f;
	case Level::Level_2:
		return 0.0004f;
	case Level::Level_3:
		return 0.001f;
	case Level::Level_4:
		return 0.002f;
	case Level::Level_5:
		return 0.0035f;
	}
}

float CLevel::getTruckStep()
{
	switch (this->lev) {
	case Level::Level_1:
		return -0.0005f;
	case Level::Level_2:
		return -0.0007f;
	case Level::Level_3:
		return -0.002f;
	case Level::Level_4:
		return -0.003f;
	case Level::Level_5:
		return -0.0045f;
	}
}

float CLevel::getBirdStep() {
	switch (this->lev) {
	case Level::Level_1:
		return -0.0003f;
	case Level::Level_2:
		return -0.0005f;
	case Level::Level_3:
		return -0.0012f;
	case Level::Level_4:
		return -0.0022f;
	case Level::Level_5:
		return -0.003f;
	}
}

float CLevel::getDinausorStep() {
	switch (this->lev) {
	case Level::Level_1:
		return 0.0002f;
	case Level::Level_2:
		return 0.0004f;
	case Level::Level_3:
		return 0.001f;
	case Level::Level_4:
		return 0.0018f;
	case Level::Level_5:
		return 0.0032f;
	}
}

void CLevel::drawLevelLabel(sf::RenderWindow& window) { window.draw(this->levelLabel); }

string CLevel::getLevel() {
	return this->levelLabel.getString();
}

void CLevel::setLevel(Level _lev) {
	switch (_lev) {
	case Level::Level_1:
		this->lev = Level::Level_1;
		this->levelLabel.setString("LEVEL 1");
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