#ifndef Vehicle_h
#define Vehicle_h

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class CVehicle {
protected:
    float mX, mY;
    sf::ConvexShape convex;
public:
    CVehicle(float x, float y);
    sf::ConvexShape getShape();
    //pair<int, int> getPos();
    virtual void move(int, int) = 0;
};

class CCar : public CVehicle {
public:
    CCar();
    CCar(float x, float y);
    void move(int, int);
};

class CTruck : public CVehicle {
public:
    CTruck();
    CTruck(float x, float y);
    void move(int, int);
};


#endif