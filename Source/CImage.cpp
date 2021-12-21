#include "../Header/CImage.h"

CImage* CImage::instance = nullptr;

bool CImage::initImage() {
	const string path = "Resource/Image/";
	return welcome_view_img.loadFromFile(path + "welcome_view_img.png")
		&& carImg.loadFromFile(path + "car.png")
		&& truckImg.loadFromFile(path + "truck.png")
		&& dinausorImg.loadFromFile(path + "dinausor.png")
		&& birdImg.loadFromFile(path + "bird.png")
		&& peopleImg.loadFromFile(path + "people.png");
}

CImage::CImage() {
	if (this->initImage()) cout << "LOAD IMG SUCCESS" << endl;
	else cout << "LOAD IMG FAILED" << endl;

	carTt = new sf::Texture[5];
	truckTt = new sf::Texture[5];
	dinausorTt = new sf::Texture[5];
	birdTt = new sf::Texture[5];

	for (int i = 0; i < 5; ++i) {
		carTt[i].loadFromImage(carImg);
		truckTt[i].loadFromImage(truckImg);
		dinausorTt[i].loadFromImage(dinausorImg);
		birdTt[i].loadFromImage(birdImg);
	}

	peopleTt = new sf::Texture;
	peopleTt->loadFromImage(peopleImg);

	welcome_view_tt = new sf::Texture;
	welcome_view_tt->loadFromImage(welcome_view_img);
}

CImage* CImage::getInstance() {
	if (!instance) instance = new CImage;
	return instance;
}

CImage::~CImage() {
	delete[] carTt;
	delete[] truckTt;
	delete[] dinausorTt;

	delete peopleTt;
	delete welcome_view_tt;
}

sf::Texture* CImage::getWelcomeViewTexture() const { return this->welcome_view_tt; }

sf::Image CImage::getCarImage() const { return carImg; }
sf::Texture* CImage::getCarTexture() const { return carTt; }

sf::Image CImage::getTruckImage() const { return truckImg; }
sf::Texture* CImage::getTruckTexture() const { return truckTt; }

sf::Image CImage::getDinausorImage() const { return dinausorImg; }
sf::Texture* CImage::getDinausorTexture() const { return dinausorTt; }

sf::Image CImage::getBirdImage() const { return birdImg; }
sf::Texture* CImage::getBirdTexture() const { return birdTt; }

sf::Image CImage::getPeopleImg() const { return peopleImg; }
sf::Texture* CImage::getPeopleTexture() const { return peopleTt; }