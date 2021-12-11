#include "../Header/CGame.h"

CGame* game;

void func() {
    while (game->isRuning())
        game->render();
}

int main() {
 //   game = CGame::getInstance();
    game = new CGame();

    //game->sprite.setTexture(game->localImage.getCarTexture());
    ////game->sprite.setScale(f, 0.1f);
    //game->sprite.setPosition(500.0f, 300.0f);
    
    sf::Thread thread(& func);
    thread.launch();
    //system("pause");
    while (game->isRuning()) {
        game->update();
    }
    return 0;
}