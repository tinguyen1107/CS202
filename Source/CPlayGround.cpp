#include "..\Header\CPlayGround.h"

CPlayground::CPlayground(float x, float y, float width, float height, float top_bottom_space, float space, float horizontal) : pos(sf::Vector2f(x, y)) {
	const int numOfLines = 5;
	for (int i = 0; i < numOfLines; i++)
		this->initHorizontalLine(x + horizontal, y + top_bottom_space + (float)i * space, width - 2.0f * horizontal);
	initBorder(horizontal, width, height);
}

void CPlayground::draw(sf::RenderWindow& window) {
	//for (int i = 0; i < this->lines.size(); ++i) window.draw(lines[i]);
}

void CPlayground::initHorizontalLine(float x, float y, float width) {
	sf::VertexArray  line(sf::LinesStrip, 2);
	line[0].position = sf::Vector2f(x, y);
	line[1].position = sf::Vector2f(x + width, y);

	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Blue;

	this->lines.push_back(line);
}

void CPlayground::initBorder(float horizontal, float width, float height) {
	sf::VertexArray  line(sf::LinesStrip, 5);
	line[0].position = sf::Vector2f(pos.x + horizontal, pos.y);
	line[1].position = sf::Vector2f(pos.x + width - horizontal, pos.y);
	line[2].position = sf::Vector2f(pos.x + width - horizontal, pos.y + height);
	line[3].position = sf::Vector2f(pos.x + horizontal, pos.y + height);
	line[4].position = sf::Vector2f(pos.x + horizontal, pos.y);

	line[0].color = sf::Color::Red;
	line[4].color = sf::Color::Red;
	line[1].color = sf::Color::Blue;

	this->lines.push_back(line);
}
