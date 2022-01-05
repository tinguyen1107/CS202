#ifndef CSound_h
#define CSound_h

#include <SFML/Audio.hpp>
#include <iostream>
#include "CCirclesAndText.h"
#include "CFont.h"

using namespace std;

class CSoundEffect {
protected:
	sf::SoundBuffer *soundBuffer;
	sf::Sound *sound;
public:
	CSoundEffect(string path, int volume = 100);
	~CSoundEffect();

	void playSound();
};

class CSound {
public:
	CSoundEffect* intro;
	CSoundEffect* car_collision;
	CSoundEffect* truck_collision;
	CSoundEffect* bird_collision;
	CSoundEffect* dinausor_collision;
	CSoundEffect* people_move;
	CSoundEffect* playing;
	CSoundEffect* waiting;

	static CSound* getInstance();
	~CSound();

	void setStateLabel(bool _isPlaying);

	void toggleActive(bool _update = false);

	void drawLabelTo(sf::RenderWindow& window);
private:
	bool isActive;
	bool isPlaying;

	static CSound* instance;
	CSound();

	CCirclesAndText* label;
	CFont* localFont;
};

#endif