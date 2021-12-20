#ifndef CSound_h
#define CSound_h

#include <SFML/Audio.hpp>

class CSound {
public:
	sf::SoundBuffer buffer;
	sf::Sound success;

	static CSound* getInstance();
	~CSound();
private:
	static CSound* instance;
	CSound();
};

#endif