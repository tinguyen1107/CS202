#ifndef CLevel_h
#define CLevel_h

enum class Level {
	Level_1, Level_2,
	Level_3, Level_4, Level_5
};

class CLevel {
private: 
	Level lev;
public:
	CLevel(Level _lev = Level::Level_1): lev(_lev) {}
	 
	/* GET FUNCTION */
	float getDistance();

	float getCarStep();
	float getTruckStep();
	float getBirdStep();
	float getDinausorStep();

	/* MODIFY FUNCTION */
	bool upLevel();
};

#endif