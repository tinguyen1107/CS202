#ifndef CTrafficLight_h
#define CTrafficLight_h

#include <SFML/Graphics.hpp>
#include <time.h> 
#include "CCirclesAndText.h"

class CTrafficLight {
public:
	static CTrafficLight* instance;
	static CTrafficLight& getInstance();

	void drawTo(sf::RenderWindow& window);

	void setActive(bool _isAc);

	bool carTrafficLight();
	bool truckTrafficLight();

	void updateTrafficLight(double car_interval = 20, double truck_interval = 20);

	~CTrafficLight();

	void drawLabelTo(sf::RenderWindow& window);

private:
	CTrafficLight();
	void updateLight();

	bool isActive;
	bool car_tl; // true mean allow to run
	bool truck_tl; // false mean must stop

	time_t start;
	time_t timer;

	int car_lastTime;
	int truck_lastTime;

	sf::CircleShape* carLight; 
	sf::CircleShape* truckLight;

	CCirclesAndText* label;
	CFont* font;
};

#endif