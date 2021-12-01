#ifndef header_h
#define header_h

#include "./Animal/CAnimal.h"
#include "./Vehicle/CVehicle.h"

void GotoXY(int x, int y);
void FixConsoleWindow();

class CPeople {
private:
    int mX, mY;
    bool mState;
public:
    CPeople();
    void up(int);
    void left(int);
    void right(int);
    void down(int);
    bool isImpact(const CVehicle*&);
    bool isImpact(const CAnimal*&);
    bool isFinish();
    bool isDead();
};

class CGame {
private:
    CTruck* axt;
    CCar* axh;
    CDinausor* akl;
    CBird* ac;
    CPeople cn;
public:
    CGame();
    void drawGame();
    ~CGame();
    CPeople getPeople();
    CVehicle* getVehicle();
    CAnimal* getAnimal();
    void resetGame();
    void exitGame();
    void startGame();
    void loadGame();
    void saveGame();
    void pauseGame();
    void resumeGame();
    void updatePosPeople(char);
    void updatePosVehicle();
    void updatePosAnimal();
};

#endif
