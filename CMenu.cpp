#include "CMenu.h"

CMenu::CMenu(vector<string> optString, float width, float height) {
	MAX_NUM_OF_OPT = optString.size();
	for (int i = 0; i < optString.size(); i++) {
		sf::Text opt;
		opt.setFont(font.Regular);
		opt.setFillColor(sf::Color(255, 255, 255));
		opt.setString(optString[i]);
		opt.setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_OF_OPT + 1) * (i+1)));

		optText.push_back(opt);
	}
	optText[0].setFillColor(sf::Color::Red);
	selectedIndex = 0;

	//sf::Image image;
	//if (image.loadFromFile("Resource/Image/B04284_01_04.jpeg")) cout << "TRUEE";

	//sf::Texture texture;
	////if (texture.loadFromFile("Resource/Image/a.png")) cout << "TRUEE";
	//texture.loadFromImage(image);
	//this->sprite.setTexture(texture);
	//sprite.setScale(0.5f, 0.5f);
	//sprite.setPosition(100.0f, 100.0f);
}

CMenu::~CMenu() {}

void CMenu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < MAX_NUM_OF_OPT; i++)
		window.draw(optText[i]);
	//window.draw(sprite, sf::RenderStates::Default);
}

void CMenu::MoveUp() {
	if (selectedIndex - 1 >= 0) {
		optText[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex--;
		optText[selectedIndex].setFillColor(sf::Color::Red);
	}
}

void CMenu::MoveDown() {
	if (selectedIndex + 1 < MAX_NUM_OF_OPT) {
		optText[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex++;
		optText[selectedIndex].setFillColor(sf::Color::Red);
	}
}

int CMenu::GetPressedItem() { return selectedIndex; }