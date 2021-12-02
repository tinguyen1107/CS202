#include "header.h"

//CGame cg;

int main() {
    /*------------------------------------*/
    /* PREPARE */
    /*------------------------------------*/
    /* Set Console */
    FixConsoleWindow(1070, 570);
    
    /* First Menu*/
    CMenu firstMenu("Menu", 2, 17, 5);
    firstMenu.addOpt("New game");
    firstMenu.addOpt("Load game");
    firstMenu.addOpt("Settings");

    CMenu secondaryMenu("Load data", 2, 17, 3);
    secondaryMenu.addOpt("Please input path to file:");
    
    /* Clear */
    system("cls");

    /*------------------------------------*/
    /* PRINT OUT */
    /*------------------------------------*/
    /* Print Playground */
    DrawRect(3, 1, 101, 30, true, 20, 5);

    /* Print First Menu */
    firstMenu.drawMenu(108, 1);

    switch (firstMenu.getSelected()) {
    case 0:
        break;
    case 1:
        secondaryMenu.drawMenu(108, 1);
        break;
    case 2:
        break;
    }

    GotoXY(3, 31);
    return 0;
}
