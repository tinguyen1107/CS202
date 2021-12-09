#include "CVehicle.h"

CVehicle::CVehicle(float x, float y): mX(x), mY(y) {}

sf::ConvexShape CVehicle::getShape() { return this->convex; }

CCar::CCar(): CVehicle(0,0) {
}

CCar::CCar(float x, float y): CVehicle(x, y) {
	this->convex.setPointCount(8);

	this->convex.setPoint(0, sf::Vector2f(0, 25));
	this->convex.setPoint(1, sf::Vector2f(60, 25));
	this->convex.setPoint(2, sf::Vector2f(60, 13));
	this->convex.setPoint(3, sf::Vector2f(40, 10));
	this->convex.setPoint(4, sf::Vector2f(32, 0));
	this->convex.setPoint(5, sf::Vector2f(15, 0));
	this->convex.setPoint(6, sf::Vector2f(12, 10));
	this->convex.setPoint(7, sf::Vector2f(0, 13));

	this->convex.setOutlineColor(sf::Color::Cyan);
	this->convex.setFillColor(sf::Color::Black);
	this->convex.setOutlineThickness(1);
	this->convex.setPosition(x, y);
}

void CCar::move(float x, float y) {
	this->mX += x;
	this->mY += y;

	this->convex.setPosition(this->mX, this->mY);
}

CTruck::CTruck() : CVehicle(0, 0) {}

CTruck::CTruck(float x, float y) : CVehicle(x, y) {
	this->convex.setPointCount(7);

	this->convex.setPoint(0, sf::Vector2f(0, 30));
	this->convex.setPoint(1, sf::Vector2f(60, 30));
	this->convex.setPoint(2, sf::Vector2f(60, 0));
	this->convex.setPoint(3, sf::Vector2f(18, 0));
	this->convex.setPoint(4, sf::Vector2f(18, 14));
	this->convex.setPoint(5, sf::Vector2f(5, 14));
	this->convex.setPoint(6, sf::Vector2f(0, 20));


	this->convex.setOutlineColor(sf::Color::Cyan);
	this->convex.setFillColor(sf::Color::Black);
	this->convex.setOutlineThickness(1);
	this->convex.setPosition(x, y);
}

void CTruck::move(float x, float y) {
	this->mX += x;
	this->mY += y;

	this->convex.setPosition(this->mX, this->mY);
}
