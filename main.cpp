#include <iostream>
#include <X11/Xlib.h>
#include "Game.h"

using namespace std;

int main() {
    Game game;
    cout << "Starting Game" << endl;
    while(true){
        game.playGame();
    }
}