#include "CGame.h"

CGame* game;

sf::Mutex mutex;

void func() {
    while (game->isRuning()) {
        game->render();
    }
}

int main() {
 //   game = CGame::getInstance();
    game = new CGame;
    
    sf::Thread thread(& func);
    thread.launch();
    //system("pause");
    while (game->isRuning()) {
        game->update();
    }
    return 0;
}