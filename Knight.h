//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include <string>
#include "Piece.h"

class Knight: public Piece {

public:
    Knight(Color color_, int row, int col){
        color = color_;
        curRow = row;
        curCol = col;
    }
    const string type() const;
    bool move(int row, int col);
};


#endif //CHESS_KNIGHT_H
