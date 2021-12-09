#ifndef CVehicle_h
#define CVehicle_h

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
    virtual void move(float, float) = 0;
};

class CCar : public CVehicle {
public:
    CCar();
    CCar(float x, float y);
    void move(float, float);
    void setPos(float x, float y) {
        this->convex.setPosition(x, y);
    }
};

class CTruck : public CVehicle {
public:
    CTruck();
    CTruck(float x, float y);
    void move(float, float);
};


#endif