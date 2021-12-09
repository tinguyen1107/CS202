#include "CVehicle.h"

CVehicle::CVehicle(float x, float y): mX(x), mY(y) {}

sf::ConvexShape CVehicle::getShape() { return this->convex; }

CCar::CCar(): CVehicle(0,0) {
}

CCar::CCar(float x, float y): CVehicle(x, y) {
	this->convex.setPointCount(8);

	this->convex.setPoint(0, sf::Vector2f(0, 30));
	this->convex.setPoint(1, sf::Vector2f(60, 30));
	this->convex.setPoint(2, sf::Vector2f(60, 13));
	this->convex.setPoint(3, sf::Vector2f(45, 13));
	this->convex.setPoint(4, sf::Vector2f(45, 0));
	this->convex.setPoint(5, sf::Vector2f(15, 0));
	this->convex.setPoint(6, sf::Vector2f(15, 13));
	this->convex.setPoint(7, sf::Vector2f(0, 13));

	this->convex.setOutlineThickness(0);
	this->convex.setPosition(x, y);
}

void CCar::move(int, int) {
	this->mX += (float)0.01;
	this->convex.setPosition(this->mX, this->mY);
}

CTruck::CTruck() : CVehicle(0, 0) {}

CTruck::CTruck(float x, float y) : CVehicle(x, y) {
	this->convex.setPointCount(6);

	this->convex.setPoint(0, sf::Vector2f(0, 30));
	this->convex.setPoint(1, sf::Vector2f(60, 30));
	this->convex.setPoint(2, sf::Vector2f(60, 0));
	this->convex.setPoint(3, sf::Vector2f(15, 0));
	this->convex.setPoint(4, sf::Vector2f(15, 13));
	this->convex.setPoint(5, sf::Vector2f(0, 13));

	this->convex.setOutlineThickness(0);
	this->convex.setPosition(x, y);
}

void CTruck::move(int, int) {
	this->mX -= (float)0.01;
	this->convex.setPosition(this->mX, this->mY);
}
