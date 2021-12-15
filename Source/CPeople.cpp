#include "../Header/CPeople.h"

CPeople::CPeople(sf::Texture& texture, float x, float y)
	: mX(x), mY(y), originPosition(sf::Vector2f(x, y)), mState(true) {
	this->sprite.setTexture(texture);
	sf::FloatRect localBounds = this->sprite.getLocalBounds();
	this->sprite.setOrigin(localBounds.left + localBounds.width / 2.0f,
		localBounds.top + localBounds.height);
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

void CPeople::backToOriginPosision() { 
	this->mX = originPosition.x;
	this->mY = originPosition.y;
	this->sprite.setPosition(originPosition); 
}

bool CPeople::isImpact(const CVehicle*&) { return false; }

bool CPeople::isImpact(const CAnimal*&) { return false; }

bool CPeople::isImpact(vector<CCar> cars, CImage& img) {
	sf::FloatRect localBounds = this->sprite.getLocalBounds();
	if ((this->mY - localBounds.height > 120.0f * 4.0f)
		|| (this->mY < 120.0f * 3.0f)) return false;

	for (int i = 0; i < cars.size(); ++i)
		if (PixelPerfectCollision(sprite, cars[i].getSprite(), img.getPeopleImg(), img.getCarImage()))
			return true;
	return false;
}

bool CPeople::isImpact(vector<CTruck> trucks, CImage& img) {
	sf::FloatRect localBounds = this->sprite.getLocalBounds();
	if ((this->mY - localBounds.height > 120.0f * 5.0f)
		|| (this->mY < 120.0f * 4.0f)) return false;

	for (int i = 0; i < trucks.size(); ++i)
		if (PixelPerfectCollision(sprite, trucks[i].getSprite(), img.getPeopleImg(), img.getTruckImage()))
			return true;
	return false;
}

bool CPeople::isImpact(vector<CBird> birds, CImage& img) {
	sf::FloatRect localBounds = this->sprite.getLocalBounds();
	if ((this->mY - localBounds.height > 120.0f * 2.0f)
		|| (this->mY < 120.0f * 1.0f)) return false;

	for (int i = 0; i < birds.size(); ++i)
		if (PixelPerfectCollision(sprite, birds[i].getSprite(), img.getPeopleImg(), img.getBirdImage()))
			return true;
	return false;
}

bool CPeople::isImpact(vector<CDinausor> dinausors, CImage& img) {
	sf::FloatRect localBounds = this->sprite.getLocalBounds();
	if ((this->mY - localBounds.height > 120.0f * 3.0f)
		|| (this->mY < 120.0f * 2.0f)) return false;

	for (int i = 0; i < dinausors.size(); ++i)
		if (PixelPerfectCollision(sprite, dinausors[i].getSprite(), img.getPeopleImg(), img.getDinausorImage()))
			return true;
	return false;
}

bool CPeople::isFinish() {
	if (this->mY < 120.0f * 1.0f) return true;
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
				vecA = inverseA.transformPoint((float)x, (float)y);
				vecB = inverseB.transformPoint((float)x, (float)y);

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