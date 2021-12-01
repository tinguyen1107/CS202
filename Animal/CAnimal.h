#ifndef CAnimal_h
#define CAnimal_h

// #include "../Base/Base.h"

class CAnimal {
private:
    int mX, mY;
public:
    virtual void move(int, int);
    virtual void tell();
};

class CBird : CAnimal {

};

class CDinausor : CAnimal {

};

#endif
