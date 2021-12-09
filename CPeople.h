#ifndef CPeople_h
#define CPeople_h

#include "CAnimal.h"
#include "CVehicle.h"

#include <SFML/Graphics.hpp>

class CPeople {
private:
    int mX, mY;
    bool mState;

    sf::RectangleShape shape;

public:
    CPeople(float x = 54, float y = 30);
    void up(float);
    void left(float);
    void right(float);
    void down(float);
    bool isImpact(const CVehicle*&);
    bool isImpact(const CAnimal*&);
    bool isFinish();
    bool isDead();

    sf::RectangleShape getShape();
};

#endif