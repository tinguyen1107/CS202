#include "CAnimal.h"

#include <iostream>

using namespace std;

/*-------------------------------------------------------------*/
/* CLASS Animal */
/*-------------------------------------------------------------*/
CAnimal::CAnimal(int x, int y) : mX(x), mY(y) {}

pair<int, int> CAnimal::getPos() {
	pair<int, int> pos;
	pos.first = mX;
	pos.second = mY;
	return pos;
}

void CAnimal::move(int x, int y) { mX += x; mY += y; }

/*-------------------------------------------------------------*/
/* CLASS BIRD */
/*-------------------------------------------------------------*/
CBird::CBird(int x, int y) : CAnimal(x, y) {};

void CBird::tell() { cout << "Bird tell" << endl; }

/*-------------------------------------------------------------*/
/* CLASS DINAUSOR */
/*-------------------------------------------------------------*/
CDinausor::CDinausor(int x, int y) : CAnimal(x, y) {};

void CDinausor::tell() { cout << "Bird tell" << endl; }