#ifndef CVehicle_h
#define CVehicle_h

#include <iostream>
using namespace std;

class CVehicle {
private:
    int mX, mY;
public:
    CVehicle(int x, int y);
    pair<int, int> getPos();
    void move(int, int);
};

class CTruck : CVehicle {
public:
    CTruck(int x, int y);
};

class CCar : CVehicle {
public:
    CCar(int x, int y);
};

#endif
