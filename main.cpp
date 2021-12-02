#include "header.h"

//CGame cg;

int main() {
    /*------------------------------------*/
    /* PREPARE */
    /*------------------------------------*/
    /* Set Console */
    FixConsoleWindow(900, 570);
    
    /* Primary Menu*/
    CMenu primaryMenu("Menu", 2, 17, 5);
    primaryMenu.addOpt("New game");
    primaryMenu.addOpt("Load game");
    primaryMenu.addOpt("Settings");

    /* Secondary Menu */
    CMenu secondaryMenu("Load data", 2, 30, 4, false);
    secondaryMenu.addOpt("Please input path to file:");
    string path;
    
    /* Clear */
    system("cls");

    /*------------------------------------*/
    /* PRINT OUT */
    /*------------------------------------*/
    /* Print Primary Menu */
    primaryMenu.drawMenu(45, 12);

    switch (primaryMenu.getSelected()) {
    case 0:
        /* Print Playground */
        DrawRect(3, 1, 101, 30, true, 20, 5);
        break;
    case 1:
        /* Print Secondary Menu */
        secondaryMenu.drawMenu(40, 1);
        cin >> path;
        break;
    case 2:
        break;
    }

    GotoXY(3, 31);
    return 0;
}
