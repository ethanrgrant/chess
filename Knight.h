//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include <string>
#include "Piece.h"

class Knight: public Piece {

public:
    Color color;
    Knight(Color color2){
        color = color2;
    }
    bool move();
    const string type() const;
};


#endif //CHESS_KNIGHT_H
