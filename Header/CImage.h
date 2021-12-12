#ifndef CImage_h
#define CImage_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class CImage {
private:
	sf::Image carImg;
	sf::Texture* carTt;

	sf::Image truckImg;
	sf::Texture* truckTt;

	sf::Image dinausorImg;
	sf::Texture* dinausorTt;

	sf::Image birdImg;
	sf::Texture* birdTt;

	sf::Image peopleImg;
	sf::Texture* peopleTt;

	bool initImage();

public:
	CImage();
	~CImage();

	sf::Image getCarImage() const;
	sf::Texture* getCarTexture() const;

	sf::Image getTruckImage() const;
	sf::Texture* getTruckTexture() const;

	sf::Image getDinausorImage() const;
	sf::Texture* getDinausorTexture() const;

	sf::Image getBirdImage() const;
	sf::Texture* getBirdTexture() const;

	sf::Image getPeopleImg() const;
	sf::Texture* getPeopleTexture() const;
};

#endif