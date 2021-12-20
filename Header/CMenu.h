#ifndef CMenu_h
#define CMenu_h

#include "CFont.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

class CMenu {
public:
	CMenu(vector<string> opt, float width, float height, bool inputPath = false);
	~CMenu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();

	void updateTextField(sf::Event event);

private:
	int MAX_NUM_OF_OPT;
	int selectedIndex;
	CFont* localFont;
	vector<sf::Text> optText;

	sf::Sprite sprite;

	// support TextField
	//sf::TextField tf(20);
};

#endif