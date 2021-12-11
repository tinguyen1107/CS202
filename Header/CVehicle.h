#ifndef CVehicle_h
#define CVehicle_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include "CImage.h"
using namespace std;

class CVehicle {
protected:
    float mX, mY;
    sf::Sprite sprite;
public:
    CVehicle(float x, float y);
    sf::Sprite getSprite();
    virtual void move(float, float) = 0;
};

class CCar : public CVehicle {
public:
    CCar();
    CCar(sf::Texture& texture, float x, float y);
    void move(float, float);
};

class CTruck : public CVehicle {
public:
    CTruck();
    CTruck(sf::Texture& texture, float x, float y);
    void move(float, float);
};

#endif