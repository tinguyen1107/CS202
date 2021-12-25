#ifndef CPlayGround_h
#define CPlayGround_h

#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;

class CPlayground {
public:
	static CPlayground& getInstance();

	/* --- DEFINE CONSTANT --- */
	const float left = 340.0f;
	const float right = 980.0f;
	const float top = 20.0f;
	const float bottom = 620.0f;

	const float width = right - left;
	const float height = bottom - top;

	const float y_finish = 80.0f;
	const float y_start = 620.0f;

	~CPlayground();
private:
	static CPlayground* instance;
	CPlayground();
};

#endif