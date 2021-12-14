#include "../Header/CLevel.h"

#include <cstdlib>

float CLevel::getDistance() {
	int i = rand() % 150;

	switch (this->lev) {
	case Level::Level_1:
		return 350.0f + i;
	case Level::Level_2:
		return 300.0f + i;
	case Level::Level_3:
		return 250.0f + i;
	case Level::Level_4:
		return 200.0f + i;
	case Level::Level_5:
		return 150.0f + i;
	}
}

float CLevel::getCarStep() {
	switch (this->lev) {
	case Level::Level_1:
		return 0.0002f;
	case Level::Level_2:
		return 0.0008f;
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
		return -0.001f;
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
		return -0.0007f;
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
		return 0.0008f;
	case Level::Level_3:
		return -0.001f;
	case Level::Level_4:
		return -0.0018f;
	case Level::Level_5:
		return -0.0032f;
	}
}

bool CLevel::upLevel() {
	switch (this->lev) {
	case Level::Level_1:
		this->lev = Level::Level_2;
		break;
	case Level::Level_2:
		this->lev = Level::Level_3;
		break;
	case Level::Level_3:
		this->lev = Level::Level_4;
		break;
	case Level::Level_4:
		this->lev = Level::Level_5;
		break;
	case Level::Level_5:
		return false;
	}
	return true;
}
