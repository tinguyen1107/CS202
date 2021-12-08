#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "CGame.h"

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

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