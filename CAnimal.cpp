#include "CAnimal.h"
#include "CAnimal.h"

CAnimal::CAnimal(float x, float y) : mX(x), mY(y) {}

sf::ConvexShape CAnimal::getShape() { return this->convex; }

CBird::CBird(): CAnimal(0, 0) {}

CBird::CBird(float x, float y) : CAnimal(x, y) {
	this->convex.setPointCount(12);

	this->convex.setPoint(0, sf::Vector2f(0, 0));
	this->convex.setPoint(1, sf::Vector2f(20, 0));
	this->convex.setPoint(2, sf::Vector2f(20, 12));
	this->convex.setPoint(3, sf::Vector2f(40, 12));
	this->convex.setPoint(4, sf::Vector2f(40, 0));
	this->convex.setPoint(5, sf::Vector2f(60, 0));
	this->convex.setPoint(6, sf::Vector2f(60, 20));
	this->convex.setPoint(7, sf::Vector2f(40, 20));
	this->convex.setPoint(8, sf::Vector2f(40, 30));
	this->convex.setPoint(9, sf::Vector2f(20, 30));
	this->convex.setPoint(10, sf::Vector2f(20, 20));
	this->convex.setPoint(11, sf::Vector2f(0, 20));

	this->convex.setOutlineColor(sf::Color::Cyan);
	this->convex.setFillColor(sf::Color::Black);
	this->convex.setOutlineThickness(1);
	this->convex.setPosition(x, y);
}

void CBird::move(float x, float y) {
	this->mX += x;
	this->mY += y;

	this->convex.setPosition(this->mX, this->mY);
}

void CBird::tell() {
	cout << "BIRD TELL!!" << endl;
}

CDinausor::CDinausor() : CAnimal(0, 0) {}

CDinausor::CDinausor(float x, float y) : CAnimal(x, y) {
	this->convex.setPointCount(10);

	this->convex.setPoint(0, sf::Vector2f(0, 45));
	this->convex.setPoint(1, sf::Vector2f(48, 45));
	this->convex.setPoint(2, sf::Vector2f(48, 26));
	this->convex.setPoint(3, sf::Vector2f(55, 26));
	this->convex.setPoint(4, sf::Vector2f(55, 0));
	this->convex.setPoint(5, sf::Vector2f(40, 0));
	this->convex.setPoint(6, sf::Vector2f(40, 17));
	this->convex.setPoint(7, sf::Vector2f(20, 17));
	this->convex.setPoint(8, sf::Vector2f(20, 33));
	this->convex.setPoint(9, sf::Vector2f(0, 33));

	this->convex.setOutlineColor(sf::Color::Cyan);
	this->convex.setFillColor(sf::Color::Black);
	this->convex.setOutlineThickness(1);
	this->convex.setPosition(x, y);
}

void CDinausor::move(float x, float y) {
	this->mX += x;
	this->mY += y;
}

void CDinausor::tell() {
	cout << "DINAUSOR TELL!!" << endl;
}