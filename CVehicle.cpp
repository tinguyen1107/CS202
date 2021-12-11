#include "CVehicle.h"

CVehicle::CVehicle(float x, float y): mX(x), mY(y) {}

sf::Sprite CVehicle::getSprite() { return this->sprite; }

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
