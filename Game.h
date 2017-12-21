//
// Created by Ethan Grant on 12/16/2017.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H


#include "board.h"

class Game {

public:

    Game(){
        isCheckmate = false;
        curColor = Space::Occupation::WHITE;
    }

    bool playGame();
    bool isCheckmate;
    Space::Occupation curColor;

private:

    void flipColor();
};


#endif //CHESS_GAME_H
