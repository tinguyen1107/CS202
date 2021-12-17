#include "../Header/CGame.h"

#include <fstream>

CGame* game;

void renderThread() {
    while (game->isRuning())
        game->render();
}
/* 
void func() {
    ifstream file("C:/Users/tinnguyen/CS202/Source/data.json");
    if (!file.is_open()) cout << "FAIL" << endl;
    Json::Value actualValue;
    Json::Reader reader;

    reader.parse(file, actualValue);

    file.close();
    cout << "Total json data: " << endl << actualValue << endl;

    cout << "Level: " << actualValue["level"] << endl;

    ofstream ofile("C:/Users/tinnguyen/CS202/Source/dataCopy.json");
    if (!ofile.is_open()) cout << "FAIL" << endl;
    Json::Value value;
    
    value["level"] = "Level_1";

    ofile << value;
    ofile.close();
}
*/

int main() {
    // func();
    game = new CGame();

    sf::Thread thread(& renderThread);
    thread.launch();
    while (game->isRuning()) {
        game->update();
    }
    return 0;
}