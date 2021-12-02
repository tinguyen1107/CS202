#ifndef CAnimal_h
#define CAnimal_h

// #include "../Base/Base.h"

class CAnimal {
private:
    int mX, mY;
public:
    virtual void move(int, int) = 0;
    virtual void tell() = 0;
};

class CBird : CAnimal {
    void move(int, int);
    void tell();
};

class CDinausor : CAnimal {
    void move(int, int);
    void tell();

};

#endif
