#include "../Header/CVehicle.h"

CVehicle::CVehicle(float x, float y): mX(x), mY(y), originPosition(sf::Vector2f(x, y)) {}

sf::Sprite CVehicle::getSprite() { return this->sprite; }

float CVehicle::getHorizontalPosition() {
	return this->mX;
}

void CVehicle::setHorizontalPosition(float x) {
	this->mX = x;
	this->sprite.setPosition(mX, mY);
}

void CVehicle::backToOriginPosision() {
	this->mX = originPosition.x;
	this->mY = originPosition.y;
	this->sprite.setPosition(originPosition);
}

CCar::CCar(): CVehicle(0,0) {}

CCar::CCar(sf::Texture& texture, float x, float y): CVehicle(x, y) {
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
}

void CCar::move(float x, float y) {
	this->mX += x;
	this->mY += y;

	this->sprite.setPosition(this->mX, this->mY);
}

CTruck::CTruck() : CVehicle(0, 0) {}

CTruck::CTruck(sf::Texture& texture, float x, float y) : CVehicle(x, y) {
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
}

void CTruck::move(float x, float y) {
	this->mX += x;
	this->mY += y;

	this->sprite.setPosition(this->mX, this->mY);
}
