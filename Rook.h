//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include <string>
#include <iostream>
#include "Piece.h"

class Rook: public Piece {

public:
    Rook(Color color_, int row, int col){
        color = color_;
        curRow = row;
        curCol = col;
    }
    bool move(int row, int col);
    const string type() const;
};


#endif //CHESS_ROOK_H
