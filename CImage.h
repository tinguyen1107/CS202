#ifndef CImage_h
#define CImage_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class CImage {
private:
	sf::Image carImg;
	sf::Texture* carTt;

	sf::Image peopleImg;
	sf::Texture* peopleTt;

	bool initImage() {
		const string path = "Resource/Image/";
		return carImg.loadFromFile(path + "car.png")
			&& peopleImg.loadFromFile(path + "people.png");
	}

public:
	CImage() {
		if (this->initImage()) cout << "LOAD IMG SUCCESS!!" << endl;
		else cout << "LOAD IMG FAILED" << endl;

		carTt = new sf::Texture[5];
		for (int i = 0; i < 5; ++i) carTt[i].loadFromImage(carImg);

		peopleTt = new sf::Texture;
		peopleTt->loadFromImage(peopleImg);
	}

	~CImage() {
		delete [] carTt;
		delete peopleTt;
	}

	sf::Image getCarImage() const { return carImg; }
	sf::Texture* getCarTexture() const { return carTt; }

	sf::Image getPeopleImg() const { return peopleImg; }
	sf::Texture* getPeopleTexture() const { return peopleTt; }
};

#endif