#include "CGame.h"

int main() {
    CGame* game;
 //   game = CGame::getInstance();
    game = new CGame;
    
    //system("pause");
    while (game->isRuning()) {
        // Update
        game->update();

        // Render
        game->render();
    }
    return 0;
}