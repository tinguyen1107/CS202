#ifndef CPeople_h
#define CPeople_h

#include "CAnimal.h"
#include "CVehicle.h"

#include <SFML/Graphics.hpp>

class CPeople {
private:
    float mX, mY;
    sf::Vector2f originPosition;

    bool mState;
    sf::Sprite sprite;

    inline sf::IntRect FToIRect(const sf::FloatRect& f);
    bool PixelPerfectCollision(const sf::Sprite& a, const sf::Sprite& b,
        const sf::Image& imgA, const sf::Image& imgB);

public:
    CPeople(sf::Texture& texture, float x = 54, float y = 30);
    void up(float);
    void left(float);
    void right(float);
    void down(float);

    void backToOriginPosision();

    bool isImpact(const CVehicle*&);
    bool isImpact(const CAnimal*&);

    bool isImpact(vector<CCar>, CImage&);
    bool isImpact(vector<CTruck>, CImage&);

    bool isImpact(vector<CBird>, CImage&);
    bool isImpact(vector<CDinausor>, CImage&);

    bool isFinish();
    bool isDead();
    sf::Sprite getSprite();
};

#endif