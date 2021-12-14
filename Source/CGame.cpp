#include "../Header/CGame.h"
#include <Windows.h>

void CGame::initVariable() {
	this->state = GameState::welcome_state;
	this->window = nullptr;
}

void CGame::initWindow() {
	this->videoMode.height = SCREEN_HEIGHT;
	this->videoMode.width = SCREEN_WIDTH;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	this->window = new sf::RenderWindow(
		this->videoMode, 
		"Crossing road", 
		sf::Style::Titlebar | sf::Style::Close, 
		settings
	);

	this->window->setActive(false);

	this->window->setFramerateLimit(500);
}

void CGame::reInitObj() {
	this->cars.clear();
	this->trucks.clear();
	this->birds.clear();
	this->dinausors.clear();

	this->initCars();
	this->initTrucks();
	this->initBirds();
	this->initDinausors();

	this->people = CPeople(*this->localImage.getPeopleTexture(), SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT);
}

//void CGame::initEnemies() {
//	this->enemy.setPosition(20.f, 10.f);
//	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
//	this->enemy.setFillColor(sf::Color::Cyan);
//	this->enemy.setOutlineColor(sf::Color::Green);
//	this->enemy.setOutlineThickness(1.f);
//}

void CGame::initTexts() {
	text.setFont(localFont.SemiBold);
	text.setString("Welcome");
	text.setCharacterSize(60);
	text.setFillColor(sf::Color::White);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f));
}

void CGame::initVertexs() {
	const int horizontal = 50;
	const int numOfLines = 5;
	const float space = 120;
	for (int i = 0; i < numOfLines; i++) {
		sf::VertexArray  line(sf::LinesStrip, 2);
		line[0].position = sf::Vector2f(horizontal, (i + 1) * space);
		line[1].position = sf::Vector2f(SCREEN_WIDTH - horizontal, (i + 1) * space);

		line[0].color = sf::Color::Red;
		line[1].color = sf::Color::Blue;

		this->lines.push_back(line);
	}
}

void CGame::initCars(int number) {
	sf::Texture* pCarTexture = localImage.getCarTexture();
	sf::Vector2u carSize = localImage.getCarImage().getSize();
	float carPosX = (-1.0f) * (float)carSize.x;
	float carPosY = 120.0f * 4.0f - (float)carSize.y;

	for (int i = 0; i < number; i++) {
		CCar car(pCarTexture[i], carPosX, carPosY);
		this->cars.push_back(car);
	}
}

void CGame::initTrucks(int number) {
	sf::Texture* pTruckTexture = localImage.getTruckTexture();
	sf::Vector2u truckSize = localImage.getTruckImage().getSize();
	float truckPosX = SCREEN_WIDTH + 1.0f;
	float truckPosY = 120.0f * 5.0f - (float)truckSize.y;

	for (int i = 0; i < number; i++) {
		CTruck truck(pTruckTexture[i], truckPosX, truckPosY);
		this->trucks.push_back(truck);
	}
}

void CGame::initBirds(int number) {
	sf::Texture* pBirdTexture = localImage.getBirdTexture();
	sf::Vector2u birdSize = localImage.getBirdImage().getSize();
	float birdPosX = SCREEN_WIDTH + 1.0f;
	float birdPosY = 120.0f * 2.0f - 40.0f - (float)birdSize.y;

	for (int i = 0; i < number; i++) {
		CBird bird(pBirdTexture[i], birdPosX, birdPosY);
		this->birds.push_back(bird);
	}
}

void CGame::initDinausors(int number) {
	sf::Texture* pDinausorTexture = localImage.getDinausorTexture();
	float dinausorPos = (-1.0f) * pDinausorTexture[0].getSize().x;

	sf::Vector2u dinausorSize = localImage.getDinausorImage().getSize();
	float dinausorPosX = (-1.0f) * dinausorSize.x;
	float dinausorPosY = 120.0f * 3.0f - (float)dinausorSize.y;

	for (int i = 0; i < number; i++) {
		CDinausor dinausor(pDinausorTexture[1], dinausorPosX, dinausorPosY);
		this->dinausors.push_back(dinausor);
	}
}

void CGame::drawCar() {
	for (int i = 0; i < 5; i++) {
		this->window->draw(this->cars[i].getSprite());
		this->window->draw(this->trucks[i].getSprite());
		this->window->draw(this->birds[i].getSprite());
		this->window->draw(this->dinausors[i].getSprite());
	}
	this->window->draw(this->people.getSprite());
}

CGame::CGame() {
	this->sprite.setTexture(*this->localImage.getCarTexture());
	this->sprite.setPosition(500.0f, 300.0f);
	
	this->initVariable();
	this->initWindow();
	//this->initEnemies();
	this->initMenu();
	this->initVertexs();

	this->initCars();
	this->initTrucks();
	this->initBirds();
	this->initDinausors();

	this->people = CPeople(*this->localImage.getPeopleTexture(), SCREEN_WIDTH/2.0f, SCREEN_HEIGHT);

	initTexts();

	cout << "DID INIT !!" << endl;
}

/*
CGame* CGame::getInstance() {
	if (instancePtr == nullptr)
		instancePtr = new CGame;
	return instancePtr;
}
*/

CGame::~CGame() {
	delete this->window;
	delete this->introMenu;
}

const bool CGame::isRuning() const { return this->window->isOpen(); }

void CGame::welcome() {
	this->window->draw(text);
}

void CGame::initMenu() {
	vector<string> optIntroMenu = { "New game", "Load game", "Setting" };
	vector<string> optCollisionMenu = { "Play again", "Back to menu", "Quit" };

	introMenu = new CMenu(optIntroMenu, 100, 150);
	collisionMenu = new CMenu(optCollisionMenu, 200, 200);
}

void CGame::drawGame() {
	for (int i = 0; i < this->lines.size(); i++)
		this->window->draw(this->lines[i]);
	drawCar();
}

void CGame::pollEvent() {
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			switch (this->state) {
			case GameState::welcome_state:
				this->handleWelcomeState();
				break;
			case GameState::intro_menu_state:
				this->handleIntroMenuState();
				break;
			case GameState::playing_state:
				this->handlePlayingState();
				break;
			case GameState::collision_state:
				this->handleCollisionMenuState();
				break;
			}
		default:
			break;
		}
	}
}

void CGame::handleWelcomeState() {
	if (this->event.key.code == sf::Keyboard::Escape)
		this->window->close();
	else if (this->event.key.code == sf::Keyboard::Enter)
		this->state = GameState::intro_menu_state;
}

void CGame::handleIntroMenuState() {
	switch (this->event.key.code) {
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		introMenu->MoveUp();
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		introMenu->MoveDown();
		break;
	case sf::Keyboard::Enter:
		int choice = introMenu->GetPressedItem();
		cout << "Choice: " << choice << endl;
		if (choice == 0)
			this->state = GameState::playing_state;
		break;
	}
}

void CGame::handlePlayingState() {
	switch (this->event.key.code) {
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		this->people.up(2);
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		this->people.down(2);
		break;
	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		this->people.left(2);
		break;
	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		this->people.right(2);
		break;
	}
}

void CGame::handleCollisionMenuState() {
	switch (this->event.key.code) {
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		collisionMenu->MoveUp();
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		collisionMenu->MoveDown();
		break;
	case sf::Keyboard::Enter:
		int choice = collisionMenu->GetPressedItem();
		cout << "Choice: " << choice << endl;
		if (choice == 0 || choice == 1) {
			this->reInitObj();
			if (choice == 0)
				this->state = GameState::playing_state;
			else
				this->state = GameState::intro_menu_state;
		}
		else this->window->close();
		break;
	}
}

void CGame::update() {
	pollEvent();
	if (this->state == GameState::playing_state) {
		if (this->isImpact()) {
			cout << "COLLISION" << endl;
			this->state = GameState::collision_state;
		}
		objMove();
		reuseObj();
	}
}

bool CGame::isImpact() {
	return this->people.isImpact(cars, localImage)
		|| this->people.isImpact(trucks, localImage)
		|| this->people.isImpact(birds, localImage)
		|| this->people.isImpact(dinausors, localImage);
}

void CGame::objMove() {
	float carStep = this->level.getCarStep();
	float truckStep = this->level.getTruckStep();
	float birdStep = this->level.getBirdStep();
	float dinausorStep = this->level.getDinausorStep();

	for (int i = 1; i < 5; i++) {
		if (cars[i - 1].getSprite().getPosition().x - cars[i].getSprite().getPosition().x > 200)
			this->cars[i].move(carStep + 0.001f * i, 0.0f);
		if (trucks[i - 1].getSprite().getPosition().x - trucks[i].getSprite().getPosition().x < -200)
			this->trucks[i].move(truckStep, 0);
		if (birds[i - 1].getSprite().getPosition().x - birds[i].getSprite().getPosition().x < -200)
			this->birds[i].move(birdStep, 0);
		if (dinausors[i - 1].getSprite().getPosition().x - dinausors[i].getSprite().getPosition().x > 200)
			this->dinausors[i].move(dinausorStep, 0);
	}

	this->cars[0].move(carStep, 0);
	this->trucks[0].move(truckStep, 0);
	this->birds[0].move(birdStep, 0);
	this->dinausors[0].move(dinausorStep, 0);
}

void CGame::reuseObj() {
	if (cars[0].getSprite().getPosition().x > SCREEN_WIDTH) {
		cars.erase(cars.begin());
		initCars(1);
	}

	if (trucks[0].getSprite().getPosition().x < (-1.0f) * localImage.getTruckImage().getSize().x) {
		trucks.erase(trucks.begin());
		initTrucks(1);
	}

	if (birds[0].getSprite().getPosition().x < (-1.0f) * localImage.getBirdImage().getSize().x) {
		birds.erase(birds.begin());
		initBirds(1);
	}

	if (dinausors[0].getSprite().getPosition().x > SCREEN_WIDTH) {
		dinausors.erase(dinausors.begin());
		initDinausors(1);
	}
}

void CGame::render() {
	this->window->clear();
	
	switch (state) {
	case GameState::welcome_state:
		welcome();
		break;
	case GameState::intro_menu_state:
		introMenu->draw(*this->window);
		this->window->draw(sprite);
		break;
	case GameState::playing_state:
		drawGame();
		break;
	case GameState::collision_state:
		collisionMenu->draw(*this->window);
	default:
		break;
	}	

	this->window->display();
}