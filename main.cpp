#include "header.h"

//CGame cg;

int main() {
    /*------------------------------------*/
    /* PREPARE */
    /*------------------------------------*/
    /* Set Console */
    FixConsoleWindow(1070, 570);
    
    /* First Menu*/
    CMenu menu("Menu", 2, 17, 5);
    menu.addOpt("New game");
    menu.addOpt("Load game");
    menu.addOpt("Settings");
    
    /* Clear */
    system("cls");

    /*------------------------------------*/
    /* PRINT OUT */
    /*------------------------------------*/
    /* Print Playground */
    DrawRect(3, 1, 101, 30, true, 20, 5);

    /* Print First Menu */
    menu.drawMenu(108, 1);

    switch (menu.getSelected()) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    }

    GotoXY(3, 31);
    return 0;
}
