#ifndef CCirclesAndText_h
#define CCirclesAndText_h

#include <SFML/Graphics.hpp>
#include "CFont.h"
#include <iostream>

using namespace std;

class CCirclesAndText {
public:
	CCirclesAndText(sf::Vector2f _pos, sf::Font& _font, string _text);
	~CCirclesAndText();

	void setPosition(sf::Vector2f _pos);
	void setColor(sf::Color _color);

	void drawTo(sf::RenderWindow& window);

private:
	sf::Vector2f pos;
	sf::CircleShape circles;
	sf::Text* text;

	const float radius = 15.0f;
};

#endif