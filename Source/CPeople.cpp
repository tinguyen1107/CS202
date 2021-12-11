#include "../Header/CPeople.h"

CPeople::CPeople(sf::Texture& texture, float x, float y) : mX(x), mY(y), mState(true) {
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
}

void CPeople::up(float x) {
	this->mY -= x;
	sprite.setPosition(this->mX, this->mY);
}

void CPeople::left(float x) {
	this->mX -= x;
	sprite.setPosition(this->mX, this->mY);
}

void CPeople::right(float x) {
	this->mX += x;
	sprite.setPosition(this->mX, this->mY);
}

void CPeople::down(float x) {
	this->mY += x;
	sprite.setPosition(this->mX, this->mY);
}

bool CPeople::isImpact(const CVehicle*&) {
	return false;
}

bool CPeople::isImpact(const CAnimal*&) {
	return false;
}

bool CPeople::isImpact(CCar car, CImage& img)
{
	return PixelPerfectCollision(sprite, car.getSprite(), img.getPeopleImg(), img.getCarImage());
}

bool CPeople::isFinish() {
	return false;
}

bool CPeople::isDead() {
	return false;
}

sf::Sprite CPeople::getSprite() {
	return this->sprite;
}

inline sf::IntRect CPeople::FToIRect(const sf::FloatRect& f) {
	return sf::IntRect((int)f.left, (int)f.top, (int)f.width, (int)f.height);
}

bool CPeople::PixelPerfectCollision(const sf::Sprite& a, const sf::Sprite& b,
	const sf::Image& imgA, const sf::Image& imgB) {
	sf::IntRect boundsA(FToIRect(a.getGlobalBounds()));
	sf::IntRect boundsB(FToIRect(b.getGlobalBounds()));
	sf::IntRect intersection;

	if (boundsA.intersects(boundsB, intersection)) {
		const sf::Transform& inverseA(a.getInverseTransform());
		const sf::Transform& inverseB(b.getInverseTransform());

		const sf::Vector2u& sizeA(imgA.getSize());
		const sf::Vector2u& sizeB(imgB.getSize());

		const sf::Uint8* pixA = imgA.getPixelsPtr();
		const sf::Uint8* pixB = imgB.getPixelsPtr();

		sf::Vector2f vecA, vecB;
		int xMax = intersection.left + intersection.width;
		int yMax = intersection.top + intersection.height;

		for (int x = intersection.left; x < xMax; x++)
			for (int y = intersection.top; y < yMax; y++) {
				vecA = inverseA.transformPoint(x, y);
				vecB = inverseB.transformPoint(x, y);

				int idxA = ((int)vecA.x + ((int)vecA.y) * sizeA.x) * 4 + 3;
				int idxB = ((int)vecB.x + ((int)vecB.y) * sizeB.x) * 4 + 3;

				if (vecA.x > 0 && vecA.y > 0 &&
					vecB.x > 0 && vecB.y > 0 &&
					vecA.x < sizeA.x && vecA.y < sizeA.y &&
					vecB.x < sizeB.x && vecB.y < sizeB.y &&
					pixA[idxA] > 0 &&
					pixB[idxB] > 0) {
					return true;
				}
			}
	}

	return false;
}