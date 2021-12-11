#include "../Header/CLevel.h"

float CLevel::getCarStep() {
	switch (this->lev) {
	case Level::Level_1:
		return 0.0005f;
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
		return -0.0007f;
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
		return -0.0004f;
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
		return 0.0005f;
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
