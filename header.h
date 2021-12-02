#ifndef header_h
#define header_h

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

#include "./Animal/CAnimal.h"
#include "./Vehicle/CVehicle.h"

using namespace std;

void GotoXY(int x, int y);
void FixConsoleWindow();
void PrintMenu(int x, int y);

void DrawBird(int x, int y);
void DrawDinausor(int x, int y);

void DrawCar(int x, int y);
void DrawTruck(int x, int y);

void DrawPeople(int x, int y);

void DrawRect(int x, int y, int width, int height, bool hasDividers, int curPosX = 0, int curPosY = 0);

class CMenu {
private:
    int w;
    int h;
    int selected;

    string title;
    vector<string> opt;
public:
    CMenu(string title, int w = 23, int h = 6);
    void addOpt(string opt);
    int getOpt();
    void drawMenu(int x, int y, int space = 1);
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
