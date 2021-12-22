#include "../Header/CAnimal.h"

CAnimal::CAnimal(float x, float y) : mX(x), mY(y), originPosition(sf::Vector2f(x, y)) {}

sf::Sprite CAnimal::getSprite()
{
	return this->sprite;
}

float CAnimal::getHorizontalPosition() {
	return this->mX;
}

void CAnimal::setHorizontalPosition(float x) {
	this->mX = x;
	this->sprite.setPosition(this->mX, this->mY);
}

void CAnimal::backToOriginPosision() { 
	this->mX = originPosition.x;
	this->mY = originPosition.y;
	this->sprite.setPosition(originPosition); 
}

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

CDinosaur::CDinosaur() : CAnimal(0, 0) {}

CDinosaur::CDinosaur(sf::Texture& texture, float x, float y) : CAnimal(x, y) {
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
}

void CDinosaur::move(float x, float y) {
	this->mX += x;
	this->mY += y;

	this->sprite.setPosition(this->mX, this->mY);
}

void CDinosaur::tell() {
	cout << "DINAUSOR TELL!!" << endl;
}