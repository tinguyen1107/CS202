#ifndef CFont_h
#define CFont_h

#include <SFML/Graphics.hpp>

class CFont {
private:
	bool initFonts();
public:
	CFont();
	sf::Font Bold;
	sf::Font SemiBold;
	sf::Font Regular;
};

#endif