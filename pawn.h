//
// Created by Ethan Grant on 12/17/2017.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include <array>
#include "Piece.h"

using namespace std;

class Pawn: public Piece{

public:
    Color color;
    Pawn(Color color2){
        color = color2;
    }
    bool move();
    const string type() const;
};


#endif //CHESS_PAWN_H
