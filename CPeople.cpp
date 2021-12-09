#include "CPeople.h"

CPeople::CPeople(float x, float y) : mX(x), mY(y), mState(true) {
	
}

void CPeople::up(float) {
}

void CPeople::left(float) {
}

void CPeople::right(float) {
}

void CPeople::down(float) {
}

bool CPeople::isImpact(const CVehicle*&) {
	return false;
}

bool CPeople::isImpact(const CAnimal*&) {
	return false;
}

bool CPeople::isFinish() {
	return false;
}

bool CPeople::isDead() {
	return false;
}
