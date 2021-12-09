#include "CPeople.h"

CPeople::CPeople(float x, float y) : mX(x), mY(y), mState(true) {
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(10, 20));
	shape.setFillColor(sf::Color::Blue);
}



void CPeople::up(float x) {
	this->mY -= x;
	shape.setPosition(this->mX, this->mY);
}

void CPeople::left(float x) {
	this->mX -= x;
	shape.setPosition(this->mX, this->mY);
}

void CPeople::right(float x) {
	this->mX += x;
	shape.setPosition(this->mX, this->mY);
}

void CPeople::down(float x) {
	this->mY += x;
	shape.setPosition(this->mX, this->mY);
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

sf::RectangleShape CPeople::getShape() { return this->shape; }
