#ifndef CFont_h
#define CFont_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

class CFont {
private:
	const std::string path = "Resource/Font/Montserrat-";
	void initFonts();
public:
	CFont();
	sf::Font SemiBold;
};

#endif