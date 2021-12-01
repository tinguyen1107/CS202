#ifndef CVehicle_h
#define CVehicle_h

class CVehicle {
private:
    int mX, mY;
public:
    virtual void move(int, int);
};

class CTruck : CVehicle {

};

class CCar : CVehicle {

};

#endif
