#ifndef CCirclesAndText_h
#define CCirclesAndText_h

#include <SFML/Graphics.hpp>
#include "CFont.h"

class CCirclesAndText {
public:
	CCirclesAndText(sf::Vector2f _pos);
	~CCirclesAndText();

	void setFont(sf::Font );

	void drawTo(sf::RenderWindow& window);

private:
	sf::Vector2f pos;
	sf::CircleShape circles;
	sf::Text text;
};

#endif