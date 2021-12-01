#include "header.h"
#include <windows.h>

void GotoXY(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}

void FixConsoleWindow() {

}
