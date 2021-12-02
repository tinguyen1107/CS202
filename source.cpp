#define _WIN32_WINNT 0x0500

#include "header.h"
#include <windows.h>

#include <iostream>

using namespace std;

void GotoXY(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}

void DrawRect(int x, int y, int width, int height, bool hasDividers, int curPosX, int curPosY) {
    GotoXY(x, y); cout << char(201);
    for (int i = 1; i < width; i++)cout << char(205);
    cout << char(187);
    GotoXY(x, height + y); cout << char(200);
    for (int i = 1; i < width; i++)cout << char(205);
    cout << char(188);
    for (int i = y + 1; i < height + y; i++) {
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

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1070, 570, TRUE);

    LONG style = GetWindowLong(console, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(console, GWL_STYLE, style);

    system("cls");

    DrawRect(3, 1, 101, 30, true, 20, 5);
}

void PrintMenu(int x, int y) {
    CMenu menu("Menu", 17, 5);
    menu.addOpt("New game");
    menu.addOpt("Load game");
    menu.addOpt("Settings");

    menu.drawMenu(x, y, 2);
}

void DrawBird(int x, int y) {
    GotoXY(x, y - 1);
    cout << char(219) << char(219);

    GotoXY(x + 2, y);
    cout << char(219) << char(219);

    GotoXY(x + 4, y - 1);
    cout << char(219) << char(219);
}

void DrawDinausor(int x, int y) {
    GotoXY(x, y);
    cout << char(219) << char(219);
    cout << char(219) << char(219);

    GotoXY(x + 2, y - 1);
    cout << char(219) << char(219);
    cout << char(219) << char(219);

    GotoXY(x + 4, y - 2);
    cout << char(219) << char(219);
}

void DrawCar(int x, int y) {
    GotoXY(x, y);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
    cout << char(219) << char(219);

    GotoXY(x + 2, y - 1);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
}

void DrawTruck(int x, int y) {
    GotoXY(x, y);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
    cout << char(219) << char(219);

    GotoXY(x + 2, y - 1);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
}

void DrawPeople(int x, int y) {
    GotoXY(x, y);
    cout << char(62) << char(60);
    GotoXY(x, y - 1);
    cout << char(219) << char(219);
}

/*-------------------------------------------------------------*/
/* MENU */
/*-------------------------------------------------------------*/

CMenu::CMenu(string title, int w, int h) : title(title), w(w), h(h), selected(0) {}

void CMenu::addOpt(string opt) { this->opt.push_back(opt); }

int CMenu::getOpt() { return selected; }

void drawMenu(int x, int y, int space) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DrawRect(x, y, w, h, false, x + (w + 1 - title.length()) / 2, y + 1);
    cout << title;
    for (int i = 0; i != opt.size(); ++i) {
        GotoXY(x + space, y + h - (opt.size() - i));
        cout << i << ". " + opt[i] + ".";
    }
    selected = 0;

    bool didConfirm = false;
    do {
        if (getch() == 13) didConfirm = true;
        else {
            SetConsoleTextAttribute(hConsole, 15);
            GotoXY(x + space, y + h - (opt.size() - selected));
            cout << selected << ". " + opt[selected] + ".";
            switch (getch()) {
            case 72:
                selected--; // up
                if (selected < 0) selected = opt.size() - 1;
                break;
            case 80:
                selected++; // down
                break;
                //case 75: left
                //case 77: right
            }
            selected = selected % opt.size();
            SetConsoleTextAttribute(hConsole, 10);
            GotoXY(x + space, y + h - (opt.size() - selected));
            cout << selected << ". " + opt[selected] + ".";
        }
    } while (!didConfirm);
    SetConsoleTextAttribute(hConsole, 15);
}