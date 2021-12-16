#ifndef CLevel_h
#define CLevel_h

#include <SFML/Graphics.hpp>
#include "CFont.h"

enum class Level {
	Level_1, Level_2,
	Level_3, Level_4, Level_5
};

class CLevel {
private:
	CFont localFont;

	Level lev;
	sf::Text levelLabel;
public:
	CLevel(Level _lev = Level::Level_1);
	 
	/* GET FUNCTION */
	float getDistance();

	float getCarStep();
	float getTruckStep();
	float getBirdStep();
	float getDinausorStep();

	void drawLevelLabel(sf::RenderWindow& window);

	/* MODIFY FUNCTION */
	void setLevel(Level _lev = Level::Level_1);
	bool upLevel();
};

#endif