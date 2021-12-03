#ifndef CAnimal_h
#define CAnimal_h

#include <iostream>

using namespace std;

class CAnimal {
private:
    int mX, mY;
public:
    CAnimal(int x, int y);
    pair<int, int> getPos();
    void move(int, int);
    virtual void tell() = 0;
};

class CBird : CAnimal {
public:
    CBird(int x, int y);
    void tell();
};

class CDinausor : CAnimal {
public:
    CDinausor(int x, int y);
    void tell();
};

#endif