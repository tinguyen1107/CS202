#ifndef CFont_h
#define CFont_h

#include <SFML/Graphics.hpp>

class CFont {
private:
	static CFont* instance;
	CFont();

	bool initFonts();
public:
	static CFont* getInstance();
	
	~CFont();

	sf::Font Bold;
	sf::Font SemiBold;
	sf::Font Regular;

	sf::Font ArialRounded;
};

#endif