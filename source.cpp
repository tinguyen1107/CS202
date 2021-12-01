#define _WIN32_WINNT 0x0500

#include "header.h"
#include <windows.h>

#include <iostream>

using namespace std;

void GotoXY(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}

void DrawRect(int x, int y, int width, int height, bool hasDividers, int curPosX = 0, int curPosY = 0) {
    GotoXY(x, y); cout << char(201);
    for (int i = 1; i < width; i++)cout << char(205);
    cout << char(187);
    GotoXY(x, height + y); cout << char(200);
    for (int i = 1; i < width; i++)cout << char(205);
    cout << char(188);
    for (int i = y + 1; i < height + y; i++)
    {
        GotoXY(x, i);
        if (hasDividers && (i - y) % 5 == 0) {
            cout << char(204);
            for (int i = 1; i < width; i++)cout << char(196);
        }
        else cout << char(186);
        GotoXY(x + width, i);
        if (hasDividers && (i - y) % 5 == 0) cout << char(185);
        else cout << char(186);
    }

    GotoXY(curPosX, curPosY);
}

void FixConsoleWindow() {
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1120, 570, TRUE);

    LONG style = GetWindowLong(console, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(console, GWL_STYLE, style);

    system("cls");

    DrawRect(3, 1, 101, 30, true, 20, 5);
}

void PrintMenu(int x, int y) {
    int w = 23;
    int h = 6;

    string title = "MENU";
    string opt1 = "1. New game.";
    string opt2 = "2. Load game.";
    string opt3 = "3. Setting.";

    int space = 3;
    DrawRect(x, y, w, h, false, x + (w-1-title.length())/2, y + 1);
    cout << title;
    GotoXY(x + space, y + h-3);
    cout << opt1;
    GotoXY(x + space, y + h-2);
    cout << opt2;
    GotoXY(x + space, y + h-1);
    cout << opt3;
}