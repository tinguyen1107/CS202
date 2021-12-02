#ifndef header_h
#define header_h

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <dos.h>

#include "./Animal/CAnimal.h"
#include "./Vehicle/CVehicle.h"

using namespace std;

void GotoXY(int x, int y);
void FixConsoleWindow(int w, int h);
void DrawRect(int x, int y, int width, int height, bool hasDividers, int curPosX = 0, int curPosY = 0, bool isThin = false);
void Clear(int x, int y, int w, int h);
void Welcome(int x, int y);
void Loading(int x, int y, int w=40, int h=2);

class CMenu {
private:
    int w, h, space, selected;
    bool isMultiplechoice;
    string title;
    vector<string> opt;
public:
    CMenu(string title, int space=1, int w = 23, int h = 6, bool isMultiplechoice=true);
    void addOpt(string opt);
    int getSelected();
    void drawMenu(int x, int y);
    void move(int x, int y, int color);
    
};

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

    void drawBird(int x, int y);
    void drawDinausor(int x, int y);
    void drawCar(int x, int y);
    void drawTruck(int x, int y);
    void drawPeople(int x, int y);
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
