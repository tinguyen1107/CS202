#ifndef CPlayGround_h
#define CPlayGround_h

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

using namespace std;

class CPlayground {
public:
	static CPlayground* instance;
	static CPlayground& getInstance();

	/* --- DEFINE CONSTANT --- */
	const float left = 340.0f;
	const float right = 980.0f;
	const float top = 20.0f;
	const float bottom = 620.0f;

	const float width = right - left;
	const float height= bottom - top;

	const float y_finish = 80.0f;
	const float y_start = 620.0f;

	

	void draw(sf::RenderWindow& window);

	~CPlayground();
private:
	CPlayground(float x = 320.0f, float y = 20.0f,
		float width = 680.0f, float height = 120.0f * 4.0f + 60.0f * 2.0f,
		float top_bottom_space = 60.0f, float space = 120.0f,
		float horizontal = 20.0f
	);

	sf::Vector2f pos;
	vector<sf::VertexArray> lines;

	void initHorizontalLine(float x, float y, float width);
	void initBorder(float horizontal, float width, float height);
};

#endif