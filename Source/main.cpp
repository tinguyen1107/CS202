#include "../Header/CGame.h"

CGame* game;

void renderThread() {
    while (game->isRuning())
        game->render();
}

int main() {
    game = new CGame();

    sf::Thread thread(& renderThread);
    thread.launch();
    while (game->isRuning()) {
        game->update();
    }
    return 0;
}