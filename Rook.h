//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include <string>
#include "Piece.h"

class Rook: public Piece {

public:
    Color color;
    Rook(Color color2){
        color = color2;
    }
    bool move();
    const string type() const;
};


#endif //CHESS_ROOK_H
