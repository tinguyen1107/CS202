#ifndef CVehicle_h
#define CVehicle_h

class CVehicle {
private:
    int mX, mY;
public:
    virtual void move(int, int) = 0;
};

class CTruck : CVehicle {
public:
    void move(int, int);
};

class CCar : CVehicle {
    void move(int, int);
};

#endif
