#ifndef CAnimal_h
#define CAnimal_h

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class CAnimal {
protected:
    float mX, mY;
    sf::ConvexShape convex;
    sf::Sprite sprite;
public:
    CAnimal(float x, float y);
    sf::ConvexShape getShape();
    sf::Sprite getSprite();
    virtual void move(float, float) = 0;
    virtual void tell() = 0;
};

class CBird : public CAnimal {
public:
    CBird();
    CBird(sf::Texture& texture, float x, float y);
    void move(float, float);
    void tell();
};

class CDinausor : public CAnimal {
public:
    CDinausor();
    CDinausor(sf::Texture& texture, float x, float y);
    void move(float x, float y);
    void tell();
};


#endif