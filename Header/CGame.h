#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <json/json.h>

#include <iostream>
#include <fstream>

#include "CFont.h"
#include "CImage.h"
#include "CSound.h"
#include "CTrafficLight.h"
#include "CCirclesAndText.h"

#include "CMenu.h"
#include "CPeople.h"
#include "CLevel.h"
#include "CPlayGround.h"

#include "../Header/TextField.h"

using namespace std;

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 640

#define WIDTH 400

#define MAX_NUM_OBJ 5

enum GameState {
	welcome_state,
	intro_menu_state,
	playing_state,
	collision_state,
	pause_state,
	wait_for_level_up_state,
	input_path_state,
	setting_menu_state
};

class CGame {
private:
	/* --- --- -- --- --- */
	/* --- PROPERTIES --- */
	/* --- --- -- --- --- */
	GameState state;
	CLevel level;

	bool pauseCars;
	bool pauseTrucks;

	bool isInputing;

	/* --- --- - --- --- */
	/* --- COMPONENT --- */
	/* --- --- - --- --- */

	/* --- WINDOW --- */
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	/* --- SUBCOMPONENT --- */
	CPlayground* playground;

	/* --- MENU --- */
	CMenu* introMenu;
	CMenu* collisionMenu;
	CMenu* pauseMenu;
	CMenu* inputMenu;
	CMenu* settingMenu;

	/* --- --- --- -- */
	/* --- OBJECT --- */
	/* --- --- --- -- */
	CPeople* people;
	CTrafficLight* trafficLight;


	// Vehicle
	vector<CCar> cars;
	vector<CTruck> trucks;

	// Animal
	vector<CBird> birds;
	vector<CDinosaur> dinausors;
	
	/* --- --- - --- --- */
	/* --- UTILITIES --- */
	/* --- --- - --- --- */
	CFont* localFont;
	CImage* localImage;
	CSound* localSound;

	// Private Functions
	void initVariable();
	void initWindow();
	void initMenu();

	void reInitObj();

	void initCars(int number = MAX_NUM_OBJ);
	void initTrucks(int number = MAX_NUM_OBJ);
	void initBirds(int number = MAX_NUM_OBJ);
	void initDinausors(int number = MAX_NUM_OBJ);

	void drawObject();

	/*------- POLL EVENT -------*/
	void handleWelcomeState();
	void handleIntroMenuState();
	void handlePlayingState();
	void handleCollisionMenuState();
	void handlePauseState();
	void handleInputMenuState();
	void handleSettingMenuState();

	/*------- UPDATE EVENT -------*/
	void checkCollision();
	void objMove();
	void reuseObj();

	void writeData(string path);
	void readData(string path);

public:
	CGame();
	~CGame();

	const bool isRuning() const;

	// Functions
	void drawGame();

	void pollEvent();
	void update();
	void render();
};

#endif