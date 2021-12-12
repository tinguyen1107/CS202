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
#include "CPeople.h"
#include "CLevel.h"

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 720

#define WIDTH 400

enum GameState {
	welcome_state,
	primary_menu_state,
	playing_state,
	collision_state,
	pause_state,
};

class CGame {
private:
	//static CGame* instancePtr;

	// Special properties
	GameState state;
	CLevel level;
	
	// Window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	/*
	* Object
	*/
	sf::Text text;
	vector<sf::VertexArray> lines;
	CMenu* primaryMenu;

	CPeople people;

	// Vehicle
	vector<CCar> cars;
	vector<CTruck> trucks;

	// Animal
	vector<CBird> birds;
	vector<CDinausor> dinausors;
	
	// User interface
	CFont localFont;
	CImage localImage;

	//CGame();

	// Private Functions
	void initVariable();
	void initWindow();
	void initPrimaryMenu();

	//void initEnemies();
	void initTexts();
	void initVertexs();

	void initCars(int number = 5);
	void initTrucks(int number = 5);
	void initBirds(int number = 5);
	void initDinausors(int number = 5);

	void drawCar();

	/*------- POLL EVENT -------*/
	void handleWelcomeState();
	void handlePrimaryMenuState();
	void handlePlayingState();
	
public:
	sf::Sprite sprite;

	CGame();
	//static CGame* getInstance();
	~CGame();

	const bool isRuning() const;

	// Functions
	void welcome();

	void drawGame();

	void pollEvent();
	void update();
	void render();
};

#endif