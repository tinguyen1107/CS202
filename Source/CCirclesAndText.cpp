#include "../Header/CCirclesAndText.h"

CCirclesAndText::CCirclesAndText(sf::Vector2f _pos) : pos(_pos) {
	float radius = 12.5f;
	
	this->circles.setRadius(radius);
	this->circles.setPosition(_pos);

	this->text.setString("Title");

	this->text.setFont()
}

CCirclesAndText::~CCirclesAndText() {}

void CCirclesAndText::drawTo(sf::RenderWindow& window) {
	window.draw(this->circles);
	window.draw(this->text);
}
