#include "../Header/CAnimal.h"

CAnimal::CAnimal(float x, float y) : mX(x), mY(y), originPosition(sf::Vector2f(x, y)) {}

sf::Sprite CAnimal::getSprite()
{
	return this->sprite;
}

void CAnimal::backToOriginPosision() { this->sprite.setPosition(originPosition); }

CBird::CBird(): CAnimal(0, 0) {}

CBird::CBird(sf::Texture& texture, float x, float y) : CAnimal(x, y) {
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
}

void CBird::move(float x, float y) {
	this->mX += x;
	this->mY += y;

	this->sprite.setPosition(this->mX, this->mY);
}

void CBird::tell() {
	cout << "BIRD TELL!!" << endl;
}

CDinausor::CDinausor() : CAnimal(0, 0) {}

CDinausor::CDinausor(sf::Texture& texture, float x, float y) : CAnimal(x, y) {
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
}

void CDinausor::move(float x, float y) {
	this->mX += x;
	this->mY += y;

	this->sprite.setPosition(this->mX, this->mY);
}

void CDinausor::tell() {
	cout << "DINAUSOR TELL!!" << endl;
}