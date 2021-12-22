#include "../Header/CImage.h"

CSingleImage::CSingleImage(string path) {
	this->texture = new sf::Texture;
	if (!texture->loadFromFile(path)) throw - 1;
	this->sprite = new sf::Sprite;
	this->sprite->setTexture(*this->texture);
}

CSingleImage::~CSingleImage() {
	delete this->texture;
	delete this->sprite;
}

void CSingleImage::drawTo(sf::RenderWindow& window){
	window.draw(*this->sprite);
}

CImage* CImage::instance = nullptr;

bool CImage::initImage() {
	const string path = "Resource/Image/";
	return 
		
		//welcome_view_img.loadFromFile(path + "welcome_view_img.png")
		//&& 
		carImg.loadFromFile(path + "car.png")
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

	try {
		this->welcome_sImg = new CSingleImage("Resource/Image/welcome_view_img.png");
		this->logo_sImg = new CSingleImage("Resource/Image/playground.png");
	}
	catch (int x) {
		if (x == -1) cout << "LOAD FAILED" << endl;
	}

	this->logo_sImg->sprite->setPosition(0.0f, 0.0f);
	cout << "LOAD IMG SUCCESS" << endl;
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

	delete welcome_sImg;
	delete logo_sImg;
}

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