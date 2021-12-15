#ifndef CPlayGround_h
#define CPlayGround_h

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

using namespace std;

class CPlayground {
public:
	CPlayground(float x = 0.0f, float y = 60.0f, 
		float width = 800.0f, float height = 120.0f * 4.0f + 60.0f * 2.0f, 
		float top_bottom_space = 60.0f, float space = 120.0f,
		float horizontal = 50.0f
	);

	void draw(sf::RenderWindow& window);
private:
	sf::Vector2f pos;
	vector<sf::VertexArray> lines;

	//vector<sf::VertexArray> ;

	void initHorizontalLine(float x, float y, float width);
	void initBorder(float horizontal, float width, float height);
};

#endif