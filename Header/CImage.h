#ifndef CImage_h
#define CImage_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class CSingleImage {
private:
	sf::Texture* texture;
public:
	sf::Sprite* sprite;

	CSingleImage(string path);
	~CSingleImage();

	void drawTo(sf::RenderWindow& window);
};

class CImage {
private:
	static CImage* instance;
	CImage();
	
	//sf::Texture* welcome_view_tt;
	//CSingleImage* welcome_sImg;
	
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
	static CImage* getInstance();
	~CImage();
	CSingleImage* welcome_sImg;
	CSingleImage* logo_sImg;

	//sf::Texture* getWelcomeViewTexture() const;

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