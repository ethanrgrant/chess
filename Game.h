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
        curColor = true;
    }

    bool playGame();
    bool isCheckmate;
private:

    bool curColor;  // true = white, false = black
    Board board;
};


#endif //CHESS_GAME_H
