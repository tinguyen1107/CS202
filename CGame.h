#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "CFont.h"
#include "CMenu.h"

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

enum GameState {
	welcome,
	primaryMenu,
	newGame,
	//playing, loadGame
};

class CGame {
private:
	//static CGame* instancePtr;

	// Special properties
	GameState state;
	
	// Window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	// Object
	sf::Text text;
	vector<sf::VertexArray> lines;

	CMenu* primaryMenu;
	
	// User interface
	CFont localFont;


	sf::RectangleShape enemy;
	//CGame();

	// Private Functions
	void initVariable();
	void initWindow();
	void initEnemies();
	void initTexts();
	void initVertexs();

	void initCars();

	void drawCar(int x, int y);
	
public:
	CGame();
	//static CGame* getInstance();
	~CGame();

	const bool isRuning() const;

	// Functions
	void welcome();
	void initPrimaryMenu();

	void drawGame();

	void pollEvent();
	void handleWelcomeState();
	void handlePrimaryMenuState();

	void update();
	void render();
};

#endif