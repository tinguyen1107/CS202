#include "../Header/CCirclesAndText.h"

CCirclesAndText::CCirclesAndText(sf::Vector2f _pos, sf::Font& _font, string _text) : pos(_pos) {	
	this->circles.setRadius(radius);
	
	this->text = new sf::Text;

	this->text->setString(_text);
	this->text->setCharacterSize(30);
	this->text->setFillColor(sf::Color::White);
	this->text->setFont(_font);
	this->setPosition(_pos);
}

CCirclesAndText::~CCirclesAndText() {
	delete this->text;
}

void CCirclesAndText::setPosition(sf::Vector2f _pos) {
	this->circles.setPosition(_pos);
	this->text->setPosition(_pos.x + radius * 2.5f, _pos.y);
}

void CCirclesAndText::setColor(sf::Color _color) {
	this->circles.setFillColor(_color);
}

void CCirclesAndText::drawTo(sf::RenderWindow& window) {
	window.draw(this->circles);
	if (this->text == nullptr) cout << "NULL" << endl;
	window.draw(*this->text);
}
