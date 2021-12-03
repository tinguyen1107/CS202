#include "CVehicle.h"

/*-------------------------------------------------------------*/
/* CLASS Vehicle */
/*-------------------------------------------------------------*/
CVehicle::CVehicle(int x, int y) : mX(x), mY(y) {}

pair<int, int> CVehicle::getPos() { 
	pair<int, int> pos;
	pos.first = mX;
	pos.second = mY;
	return pos;
}

void CVehicle::move(int x, int y) { mX += x; mY += y; }

/*-------------------------------------------------------------*/
/* CLASS TRUCK */
/*-------------------------------------------------------------*/
CTruck::CTruck(int x, int y) : CVehicle(x, y) {}

/*-------------------------------------------------------------*/
/* CLASS CAR */
/*-------------------------------------------------------------*/
CCar::CCar(int x, int y) : CVehicle(x, y) {}