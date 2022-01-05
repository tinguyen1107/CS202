#include "../Header/CTrafficLight.h"

#include <iostream>

CTrafficLight* CTrafficLight::instance = nullptr;

CTrafficLight& CTrafficLight::getInstance() {
	if (!instance) instance = new CTrafficLight;
	return *instance;
}

void CTrafficLight::drawTo(sf::RenderWindow& window) {
	if (this->isActive) {
		window.draw(*this->carLight);
		window.draw(*this->truckLight);
	}
}

void CTrafficLight::setActive(bool _isAc) { 
	this->isActive = _isAc; 
	this->label->setColor(sf::Color::Red);
	if (_isAc) {
		this->label->setColor(sf::Color::Green);
		this->start = time(0);
		this->car_tl = this->truck_tl = true;
	}
}

bool CTrafficLight::carTrafficLight() { return !this->isActive || car_tl; }
bool CTrafficLight::truckTrafficLight() { return !this->isActive || truck_tl; }

void CTrafficLight::updateTrafficLight(double car_interval, double truck_interval) {
	if (!this->isActive) return; // not need to work
	timer = time(0);
	double seconds = difftime(timer, start);
	if (((int)seconds % (int)car_interval == (car_interval - 1))
		&& !(this->car_lastTime == timer)) {
		car_tl = !car_tl;
		this->car_lastTime = (int)timer;
	}
	if ((((int)seconds % (int)truck_interval) == (truck_interval - 1))
		&& !(this->truck_lastTime == timer)) {
		truck_tl = !truck_tl;
		this->truck_lastTime= (int)timer;
	}

	updateLight();
}

CTrafficLight::~CTrafficLight() {
	delete instance;

	delete carLight;
	delete truckLight;
	delete font;
	delete label;
}

void CTrafficLight::drawLabelTo(sf::RenderWindow& window) {
	this->label->drawTo(window);
}

CTrafficLight::CTrafficLight() {
	bool truckTrafficLight();

	this->isActive = false;
	this->car_tl = this->truck_tl = true;

	this->car_lastTime = 0;
	this->truck_lastTime = 0;

	this->carLight = new sf::CircleShape(12.5f);
	this->truckLight = new sf::CircleShape(12.5f);
	
	this->label = new CCirclesAndText(sf::Vector2f(0, 0), font->getInstance()->ArialRounded, "Traffic light");
	this->label->setPosition(sf::Vector2f(40.0f, 510.0f));
	this->label->setColor(sf::Color::Red);

	this->carLight->setPosition(945.0f, 325.0f);
	this->truckLight->setPosition(350.0f, 445.0f);

	updateLight();
}

void CTrafficLight::updateLight() {
	sf::Color green = sf::Color(103, 189, 69);
	sf::Color red = sf::Color(237, 32, 36);

	this->carLight->setFillColor(this->car_tl ? green : red);
	this->truckLight->setFillColor(this->truck_tl ? green : red);
}
