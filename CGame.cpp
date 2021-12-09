#include "CGame.h"

// CGame* CGame::instancePtr = nullptr;

void CGame::initVariable() {
	this->state = GameState::welcome;
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

	this->window->setFramerateLimit(1000);
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
	const float space = 60;
	for (int i = 0; i < numOfLines; i++) {
		sf::VertexArray  line(sf::LinesStrip, 2);
		line[0].position = sf::Vector2f(horizontal, (i + 1) * space);
		line[1].position = sf::Vector2f(SCREEN_WIDTH - horizontal, (i + 1) * space);

		//line[0].color = sf::Color::Red;

		this->lines.push_back(line);
	}
}

void CGame::initCars() {
	for (int i = 0; i < 5; i++) {
		CCar car(0, 0);
		CTruck truck(700, 100);

		CBird bird(600, 200);
		CDinausor dinausor(400, 350);

		this->cars.push_back(car);
		this->trucks.push_back(truck);

		this->birds.push_back(bird);
		this->dinausors.push_back(dinausor);
	}
}

void CGame::initTrucks()
{
}

void CGame::drawCar() {
	for (int i = 0; i < 5; i++) {
		this->window->draw(this->cars[i].getShape());
		this->window->draw(this->trucks[i].getShape());
		this->window->draw(this->birds[i].getShape());
		this->window->draw(this->dinausors[i].getShape());
	}
}

CGame::CGame() {
	this->initVariable();
	this->initWindow();
	//this->initEnemies();
	this->initPrimaryMenu();
	this->initVertexs();
	this->initCars();

	initTexts();
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
	delete this->primaryMenu;
}

const bool CGame::isRuning() const { return this->window->isOpen(); }

void CGame::welcome() {
	this->window->draw(text);
}

void CGame::initPrimaryMenu() {
	vector<string> opt = { "New game", "Load game", "Setting" };
	primaryMenu = new CMenu(opt, 100, 150);
}

void CGame::drawGame() {
	for (int i = 0; i < this->lines.size(); i++)
		this->window->draw(this->lines[i]);
	drawCar();
}

void CGame::pollEvent() {
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			switch (this->state) {
			case GameState::welcome:
				handleWelcomeState();
				break;
			case GameState::primaryMenu:
				handlePrimaryMenuState();
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
		this->state = GameState::primaryMenu;
}

void CGame::handlePrimaryMenuState() {
	switch (this->event.key.code) {
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		primaryMenu->MoveUp();
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		primaryMenu->MoveDown();
		break;
	case sf::Keyboard::Enter:
		int choice = primaryMenu->GetPressedItem();
		cout << "Choice: " << choice << endl;
		if (choice == 0)
			this->state = GameState::newGame;
		break;
	}
}

void CGame::update() {
	pollEvent();
	/*sf::Vector2f pos = this->enemy.getPosition();
	pos.x += (float)0.01;
	this->enemy.setPosition(pos);*/

	this->cars[0].move(0, 0);
	this->trucks[1].move(0, 0);
}

void CGame::render() {
	this->window->clear();
	
	switch (state) {
	case GameState::welcome:
		welcome();
		break;
	case GameState::primaryMenu:
		primaryMenu->draw(*this->window);
		break;
	case GameState::newGame:
		drawGame();
		break;
	default:
		break;
	}	

	this->window->display();
}