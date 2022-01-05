#include "../Header/CMenu.h"

CMenu::CMenu(vector<string> optString, float x, float y, float height, bool isSetting) {
	MAX_NUM_OF_OPT = optString.size();
	localFont = nullptr;
	localImage = nullptr;

	for (int i = 0; i < optString.size(); i++) {
		sf::Text opt;
		opt.setFont(localFont->getInstance()->ArialRounded);
		
		opt.setFillColor(this->normalColor);
		
		opt.setOutlineThickness(1.25f);
		opt.setOutlineColor(sf::Color(255, 255, 255));

		opt.setCharacterSize(45.0);

		opt.setString(optString[i]);
		opt.setPosition(sf::Vector2f(x, y + height / (MAX_NUM_OF_OPT) * i));

		optText.push_back(opt);
	}
	optText[0].setFillColor(sf::Color::Red);
	selectedIndex = 0;
}

CMenu::~CMenu() {
	delete localFont;
	delete localImage;
}

void CMenu::draw(sf::RenderWindow& window, int id) {
	this->localImage->getInstance()->menu_bg_sImg->drawTo(window);
	for (int i = 0; i < MAX_NUM_OF_OPT; i++)
		window.draw(optText[i]);
}

void CMenu::MoveUp() {
	if (selectedIndex - 1 >= 0) {
		optText[selectedIndex].setFillColor(this->normalColor);
		selectedIndex--;
		optText[selectedIndex].setFillColor(this->selectedColor);
	}
}

void CMenu::MoveDown() {
	if (selectedIndex + 1 < MAX_NUM_OF_OPT) {
		optText[selectedIndex].setFillColor(this->normalColor);
		selectedIndex++;
		optText[selectedIndex].setFillColor(this->selectedColor);
	}
}



int CMenu::GetPressedItem() { return selectedIndex; }

void CMenu::setOption(int index, string content) {
	this->optText[index].setString(content);
}
