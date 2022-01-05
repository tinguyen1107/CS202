#ifndef CLevel_h
#define CLevel_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include "CFont.h"

enum class Level {
	Level_1, Level_2,
	Level_3, Level_4, 
	Level_5, Level_6,
	Level_7
};

class CLevel {
private:
	CFont* localFont;

	Level lev;
	sf::Text levelLabel;
public:
	CLevel(Level _lev = Level::Level_1);
	 
	/* GET FUNCTION */
	float getDistance();

	float getPeopleStep();

	float getCarStep();
	float getTruckStep();
	float getBirdStep();
	float getDinausorStep();

	bool isActiveTrafficLight();

	void drawLevelLabel(sf::RenderWindow& window);

	std::string getLevel();

	/* MODIFY FUNCTION */
	void setLevel(Level _lev = Level::Level_1);
	void loadLevel(std::string str);

	bool upLevel();
};

#endif