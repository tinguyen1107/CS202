#include "../Header/CGame.h"
#include <Windows.h>

void CGame::initVariable() {
	this->state = GameState::welcome_state;
	this->window = nullptr;
	this->pauseCars = this->pauseTrucks = false;
	this->isInputing = false;

	this->localSound->getInstance()->setStateLabel(true);
	this->playground->getInstance();
	this->trafficLight->getInstance();
}

void CGame::initWindow() {
	this->videoMode.height = SCREEN_HEIGHT;
	this->videoMode.width = SCREEN_WIDTH;

	this->window = new sf::RenderWindow(
		this->videoMode, 
		"Crossing road",
		sf::Style::Titlebar | sf::Style::Close 
	);

	this->window->setActive(false);

	this->window->setFramerateLimit(500);
}

void CGame::reInitObj() {
	for (int i = 0; i < MAX_NUM_OBJ; i++) {
		this->cars[i].backToOriginPosision();
		this->trucks[i].backToOriginPosision();
		this->birds[i].backToOriginPosision();
		this->dinausors[i].backToOriginPosision();
	}

	int random = rand() % (int)this->playground->getInstance().width + (int)this->playground->getInstance().left;
	this->people->setPosition((float)random, this->playground->getInstance().y_start);

	this->state = GameState::playing_state;
}

void CGame::initCars(int number) {
	sf::Texture* pCarTexture = localImage->getInstance()->getCarTexture();
	sf::Vector2u carSize = localImage->getInstance()->getCarImage().getSize();
	float carPosX = this->playground->getInstance().left - (float)carSize.x;
	float carPosY = 80.0f + 120.0f * 3.0f - (float)carSize.y;

	cout << "CAR      w: " << carSize.x << ", h:  " << carSize.y << endl;

	for (int i = 0; i < number; i++) {
		CCar car(pCarTexture[i], carPosX, carPosY);
		this->cars.push_back(car);
	}
}

void CGame::initTrucks(int number) {
	sf::Texture* pTruckTexture = localImage->getInstance()->getTruckTexture();
	sf::Vector2u truckSize = localImage->getInstance()->getTruckImage().getSize();
	float truckPosX = this->playground->getInstance().right;
	float truckPosY = 80.0f + 120.0f * 4.0f - (float)truckSize.y;
	
	cout << "TRUCK    w: " << truckSize.x << ", h:  " << truckSize.y << endl;

	for (int i = 0; i < number; i++) {
		CTruck truck(pTruckTexture[i], truckPosX, truckPosY);
		this->trucks.push_back(truck);
	}
}

void CGame::initBirds(int number) {
	sf::Texture* pBirdTexture = localImage->getInstance()->getBirdTexture();
	sf::Vector2u birdSize = localImage->getInstance()->getBirdImage().getSize();
	float birdPosX = this->playground->getInstance().right;
	float birdPosY = 80.0f + 120.0f * 1.0f - 40.0f - (float)birdSize.y;
	
	cout << "BIRD     w:  " << birdSize.x << ", h:  " << birdSize.y << endl;

	for (int i = 0; i < number; i++) {
		CBird bird(pBirdTexture[i], birdPosX, birdPosY);
		this->birds.push_back(bird);
	}
}

void CGame::initDinausors(int number) {
	sf::Texture* pDinausorTexture = localImage->getInstance()->getDinausorTexture();
	float dinausorPos = (-1.0f) * pDinausorTexture[0].getSize().x;

	sf::Vector2u dinausorSize = localImage->getInstance()->getDinausorImage().getSize();
	float dinausorPosX = this->playground->getInstance().left - dinausorSize.x;
	float dinausorPosY = 80.0f + 120.0f * 2.0f - (float)dinausorSize.y;

	cout << "DINOSAUR w: " << dinausorSize.x << ", h: " << dinausorSize.y << endl;

	for (int i = 0; i < number; i++) {
		CDinosaur dinausor(pDinausorTexture[1], dinausorPosX, dinausorPosY);
		this->dinausors.push_back(dinausor);
	}
}

void CGame::drawObject() {
	for (int i = 0; i < 5; i++) {
		this->window->draw(this->cars[i].getSprite());
		this->window->draw(this->trucks[i].getSprite());
		this->window->draw(this->birds[i].getSprite());
		this->window->draw(this->dinausors[i].getSprite());
	}
	this->window->draw(this->people->getSprite());
}

CGame::CGame() {
	this->initVariable();
	this->initMenu();

	this->initCars();
	this->initTrucks();
	this->initBirds();
	this->initDinausors();

	int random = rand() % (int)this->playground->getInstance().width + (int)this->playground->getInstance().left;
	this->people = new CPeople(*this->localImage->getInstance()->getPeopleTexture(), (float)random, this->playground->getInstance().y_start);

	this->initWindow();
	cout << "--- INITIALIZED ---" << endl;
}

CGame::~CGame() {
	delete this->window;

	delete this->localFont;
	delete this->localSound;
	delete this->localImage;

	delete this->introMenu;
	delete this->collisionMenu;
	delete this->pauseMenu;
	delete this->inputMenu;
	delete this->settingMenu;

	delete this->people;
	delete this->playground;
	delete this->trafficLight;
}

const bool CGame::isRuning() const { return this->window->isOpen(); }

void CGame::initMenu() {
	vector<string> optIntroMenu = { "New game", "Load game", "Setting" };
	vector<string> optCollisionMenu = { "Play again", "Back to menu", "Quit" };
	vector<string> optPauseMenu = { "Continue", "Save game", "New game", "Back to menu", "Quit"};
	vector<string> optInputMenu = { "Path", "Load", "Cancel" };
	vector<string> optSettingMenu = { this->localSound->getInstance()->getStateButton(), "Cancel"};

	introMenu = new CMenu(optIntroMenu, 80, 80, 180);
	collisionMenu = new CMenu(optCollisionMenu, 80, 80, 180);
	pauseMenu = new CMenu(optPauseMenu, 80, 80, 300);
	inputMenu = new CMenu(optInputMenu, 80, 80, 180, true);
	settingMenu = new CMenu(optSettingMenu, 80, 80, 120);
}

void CGame::drawGame() {
	this->localImage->getInstance()->road_sImg->drawTo(*this->window);
	this->drawObject();
	this->localImage->getInstance()->playground_sImg->drawTo(*this->window);
	this->trafficLight->getInstance().drawTo(*this->window);
	this->level.drawLevelLabel(*this->window);
	this->localSound->getInstance()->drawLabelTo(*this->window);
	this->trafficLight->getInstance().drawLabelTo(*this->window);
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
			case GameState::pause_state:
				this->handlePauseState();
				break;
			case GameState::input_path_state:
				this->handleInputMenuState();
				break;
			case GameState::setting_menu_state:
				this->handleSettingMenuState();
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
		if (choice == 0) { // start new game 
			this->state = GameState::playing_state;
			this->trafficLight->getInstance().setActive(this->level.isActiveTrafficLight());
			this->localSound->getInstance()->setStateLabel(true);
		}
		else if (choice == 1) { // load game
			this->state = GameState::input_path_state;
			string path;
			cout << "Input PATH to Load: " << endl;
			getline(cin, path);
			cout << "Loading from " << path << "..." << endl;
			this->readData(path);
			this->trafficLight->getInstance().setActive(this->level.isActiveTrafficLight());
			this->state = GameState::playing_state;
		} else { // setting
			this->state = GameState::setting_menu_state;
			this->settingMenu->setOption(0, this->localSound->getInstance()->getStateButton());
		}
		break;
	}
}

void CGame::handlePlayingState() {
	float peopleStep = this->level.getPeopleStep();
	// Motion control
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) this->people->up(peopleStep);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) this->people->down(peopleStep);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) this->people->left(peopleStep);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) this->people->right(peopleStep);
	// State Control
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->state = GameState::pause_state;
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
			this->level.setLevel(Level::Level_1);
			this->trafficLight->getInstance().setActive(this->level.isActiveTrafficLight());
			if (choice == 0) // Play again
				this->state = GameState::playing_state;
			else // Back To Menu
				this->state = GameState::intro_menu_state;
		} else this->window->close(); // Quit
		break;
	}
}

void CGame::handlePauseState() {
	string path;

	switch (this->event.key.code) {
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		pauseMenu->MoveUp();
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		pauseMenu->MoveDown();
		break;
	case sf::Keyboard::Enter:
		int choice = pauseMenu->GetPressedItem();
		cout << "Choice: " << choice << endl;

		switch (choice) {
		case 0: // Continue
			this->state = GameState::playing_state;
			break;
		case 1: // Save
			this->state = GameState::input_path_state;
			cout << "Input PATH to Save: " << endl;
			getline(cin, path);
			cout << "Saving to " << path << "..." << endl;
			this->writeData(path);
			this->state = GameState::pause_state;
			break;
		case 2: // New game
			this->reInitObj();
			this->level.setLevel(Level::Level_1);
			this->trafficLight->getInstance().setActive(this->level.isActiveTrafficLight());
			this->state = GameState::playing_state;
			break;
		case 3: // Back to menu
			this->reInitObj();
			this->level.setLevel(Level::Level_1);
			this->state = GameState::intro_menu_state;
			break;
		case 4: // Quit
			this->window->close();
			cout << "Close window" << endl;
			break;
		}
		break;
	}
}

void CGame::handleInputMenuState() {
	/*if 
	switch (switch_on)
	{
	default:
		break;
	}*/
}

void CGame::handleSettingMenuState() {
	switch (this->event.key.code) {
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		settingMenu->MoveUp();
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		settingMenu->MoveDown();
		break;
	case sf::Keyboard::Enter:
		int choice = settingMenu->GetPressedItem();
		cout << "Choice: " << choice << endl;

		switch (choice) {
		case 0:
			this->localSound->getInstance()->toggleActive();
			this->settingMenu->setOption(0, this->localSound->getInstance()->getStateButton());
			this->state = GameState::intro_menu_state;
			break;
		case 1:
			this->state = GameState::intro_menu_state;
			break;
		}
		break;
	}
}

void CGame::update() {
	pollEvent();
	if (this->state == GameState::playing_state) {
		int randomPause = rand();
		pauseCars = randomPause % 12 == 3;
		pauseTrucks = randomPause % 18 == 3;

		objMove();
		reuseObj();
		this->trafficLight->getInstance().updateTrafficLight(10, 10);

		if (this->people->isFinish(this->playground->getInstance().y_finish)) {
			cout << "YOU HAVE FINISHED" << endl;
			this->state = GameState::wait_for_level_up_state;
			if (this->level.upLevel()) {
				reInitObj();
				this->trafficLight->getInstance().setActive(this->level.isActiveTrafficLight());
			} else
				cout << "YOU WIN!!" << endl;
		}
	}
}

void CGame::checkCollision() {
	if (this->people->isImpact(cars, *localImage->getInstance())
		|| this->people->isImpact(trucks, *localImage->getInstance())
		|| this->people->isImpact(birds, *localImage->getInstance())
		|| this->people->isImpact(dinausors, *localImage->getInstance())) {
		cout << "COLLISION" << endl;
		this->state = GameState::collision_state;
	}
}

void CGame::objMove() {
	bool car_tl = this->trafficLight->getInstance().carTrafficLight();
	bool truck_tl = this->trafficLight->getInstance().truckTrafficLight();

	float carStep = this->level.getCarStep();
	float truckStep = this->level.getTruckStep();
	float birdStep = this->level.getBirdStep();
	float dinausorStep = this->level.getDinausorStep();

	for (int i = 1; i < 5; i++) {
		float car_curDis = cars[i - 1].getSprite().getPosition().x - cars[i].getSprite().getPosition().x;
		float truck_curDis = trucks[i - 1].getSprite().getPosition().x - trucks[i].getSprite().getPosition().x;
		float bird_curDis = birds[i - 1].getSprite().getPosition().x - birds[i].getSprite().getPosition().x;
		float dinausor_curDis = dinausors[i - 1].getSprite().getPosition().x - dinausors[i].getSprite().getPosition().x;

		if (car_curDis > this->level.getDistance() && car_tl)
			this->cars[i].move(carStep + 0.001f * i, 0.0f);
		if (truck_curDis < (- 1) * this->level.getDistance() && truck_tl)
			this->trucks[i].move(truckStep, 0);
		if (bird_curDis < (-1) * this->level.getDistance())
			this->birds[i].move(birdStep, 0);
		if (dinausor_curDis > this->level.getDistance())
			this->dinausors[i].move(dinausorStep, 0);
	}

	if (car_tl) this->cars[0].move(carStep, 0);
	if (truck_tl) this->trucks[0].move(truckStep, 0);
	this->birds[0].move(birdStep, 0);
	this->dinausors[0].move(dinausorStep, 0);
}

void CGame::reuseObj() {
	if (cars[0].getSprite().getPosition().x > SCREEN_WIDTH) {
		cars.erase(cars.begin());
		initCars(1);
	}

	if (trucks[0].getSprite().getPosition().x < (-1.0f) * localImage->getInstance()->getTruckImage().getSize().x) {
		trucks.erase(trucks.begin());
		initTrucks(1);
	}

	if (birds[0].getSprite().getPosition().x < (-1.0f) * localImage->getInstance()->getBirdImage().getSize().x) {
		birds.erase(birds.begin());
		initBirds(1);
	}

	if (dinausors[0].getSprite().getPosition().x > SCREEN_WIDTH) {
		dinausors.erase(dinausors.begin());
		initDinausors(1);
	}
}

void CGame::writeData(string path) {
	ofstream outputFile(path);
	if (!outputFile.is_open()) cout << "FAIL" << endl;
	Json::Value value;

	value["level"] = this->level.getLevel();
	value["pauseCars"] = this->pauseCars;
	value["pauseTrucks"] = this->pauseTrucks;
	value["people"]["x"] = this->people->getPosition().x;
	value["people"]["y"] = this->people->getPosition().y;

	for (int i = 0; i < MAX_NUM_OBJ; ++i) {
		value["cars"][i] = this->cars[i].getHorizontalPosition();
		value["trucks"][i] = this->trucks[i].getHorizontalPosition();
		value["birds"][i] = this->birds[i].getHorizontalPosition();
		value["dinausors"][i] = this->dinausors[i].getHorizontalPosition();
	}

	outputFile << value;
	outputFile.close();
}

void CGame::readData(string path) {
	ifstream file(path);
	if (!file.is_open()) cout << "FAIL" << endl;
	Json::Value actualValue;
	Json::Reader reader;

	reader.parse(file, actualValue);

	file.close();
	cout << "Total json data: " << endl << actualValue << endl;

	this->level.loadLevel(actualValue["level"].asString());
	this->pauseCars = actualValue["pauseCars"].asBool();
	this->pauseTrucks = actualValue["pauseTrucks"].asBool();
	this->people->setPosition(actualValue["people"]["x"].asFloat(), actualValue["people"]["y"].asFloat());

	for (int i = 0; i < MAX_NUM_OBJ; ++i) {
		this->cars[i].setHorizontalPosition(actualValue["cars"][i].asFloat());
		this->trucks[i].setHorizontalPosition(actualValue["trucks"][i].asFloat());
		this->birds[i].setHorizontalPosition(actualValue["birds"][i].asFloat());
		this->dinausors[i].setHorizontalPosition(actualValue["dinausors"][i].asFloat());
	}
}

void CGame::render() {
	this->window->clear();
	
	switch (state) {
	case GameState::welcome_state:
		this->localImage->getInstance()->welcome_sImg->drawTo(*this->window);
		break;
	case GameState::intro_menu_state:
		introMenu->draw(*this->window);
		break;
	case GameState::playing_state:
		this->checkCollision();
	case GameState::pause_state:
		drawGame();
		if (this->state == GameState::pause_state) this->pauseMenu->draw(*this->window);
		break;
	case GameState::collision_state:
		collisionMenu->draw(*this->window);
		break;
	case GameState::wait_for_level_up_state:
		break;
	case GameState::input_path_state:
		this->inputMenu->draw(*this->window);
		break;
	case GameState::setting_menu_state:
		this->settingMenu->draw(*this->window);
		//this->localSound->getInstance()->drawLabelTo(*this->window);
	default:
		break;
	}

	this->window->display();
}