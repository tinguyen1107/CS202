#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "CFont.h"

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

enum GameState {
	welcome,
	primaryMenu
	// playing, loadGame
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
	sf::Font font;
	
	// User interface
	CFont localFont;


	sf::RectangleShape enemy;
	//CGame();

	// Private Functions
	void initVariable();
	void initWindow();
	void initEnemies();
	void initFonts();
	void initTexts();
	
public:
	CGame();
	//static CGame* getInstance();
	~CGame();

	const bool isRuning() const;

	// Functions
	void welcome();

	void menu();

	void drawGame();

	void pollEvent();
	void update();
	void render();
};

#endif