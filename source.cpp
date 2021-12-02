#define _WIN32_WINNT 0x0500

#include "header.h"

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
    CMenu menu("Menu", 2, 17, 5);
    menu.addOpt("New game");
    menu.addOpt("Load game");
    menu.addOpt("Settings");

    menu.drawMenu(x, y);
}

/*-------------------------------------------------------------*/
/* CLASS MENU */
/*-------------------------------------------------------------*/

CMenu::CMenu(string title, int space, int w, int h) : title(title), w(w), h(h), selected(0), space(space) {}

void CMenu::addOpt(string opt) { this->opt.push_back(opt); }

int CMenu::getOpt() { return selected; }

void CMenu::drawMenu(int x, int y) {
    DrawRect(x, y, w, h, false, x + (w + 1 - title.length()) / 2, y + 1);
    cout << title;
    for (int i = 0; i != opt.size(); ++i) {
        GotoXY(x + space, y + h - (opt.size() - i));
        cout << i + 1 << ". " + opt[i] + ".";
    }
    selected = 0;
    move(x, y, 10);

    bool didConfirm = false;
    do {
        if (getch() == 13) didConfirm = true;
        else {
            move(x, y, 15);
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
            move(x, y, 10);
        }
    } while (!didConfirm);
}

void CMenu::move(int x, int y, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    GotoXY(x + space, y + h - (opt.size() - selected));
    cout << selected << ". " + opt[selected] + ".";
    GotoXY(x, y + h - (opt.size() - selected));
    if(color != 15) SetConsoleTextAttribute(hConsole, 15);
}

/*-------------------------------------------------------------*/
/* CLASS PEOPLE */
/*-------------------------------------------------------------*/



/*-------------------------------------------------------------*/
/* CLASS GAME */
/*-------------------------------------------------------------*/

void CGame::drawBird(int x, int y) {
    GotoXY(x, y - 1);
    cout << char(219) << char(219);

    GotoXY(x + 2, y);
    cout << char(219) << char(219);

    GotoXY(x + 4, y - 1);
    cout << char(219) << char(219);
}

void CGame::drawDinausor(int x, int y) {
    GotoXY(x, y);
    cout << char(219) << char(219);
    cout << char(219) << char(219);

    GotoXY(x + 2, y - 1);
    cout << char(219) << char(219);
    cout << char(219) << char(219);

    GotoXY(x + 4, y - 2);
    cout << char(219) << char(219);
}

void CGame::drawCar(int x, int y) {
    GotoXY(x, y);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
    cout << char(219) << char(219);

    GotoXY(x + 2, y - 1);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
}

void CGame::drawTruck(int x, int y) {
    GotoXY(x, y);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
    cout << char(219) << char(219);

    GotoXY(x + 2, y - 1);
    cout << char(219) << char(219);
    cout << char(219) << char(219);
}

void CGame::drawPeople(int x, int y) {
    GotoXY(x, y);
    cout << char(62) << char(60);
    GotoXY(x, y - 1);
    cout << char(219) << char(219);
}
