#ifndef CMenu_h
#define CMenu_h

#include "CFont.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

class CMenu {
public:
	CMenu(vector<string> opt, float width, float height);
	~CMenu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();

private:
	int MAX_NUM_OF_OPT;
	int selectedIndex;
	CFont font;
	vector<sf::Text> optText;
};

#endif
