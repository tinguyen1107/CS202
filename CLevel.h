#ifndef CLevel_h
#define CLevel_h

enum Level {
	Level_1, Level_2,
	Level_3, Level_4, Level_5
};

class CLevel {
private: 
	Level lev;
public:
	CLevel(Level _lev = Level::Level_1): lev(_lev) {}

	float getCarStep();
	float getTruckStep();
	float getBirdStep();
	float getDinausorStep();
};

#endif