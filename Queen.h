//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include <string>
#include "Piece.h"

class Queen: public Piece {

public:
    Queen(Color color_, int row, int col){
        color = color_;
        curRow = row;
        curCol = col;
    }
    const string type() const;
    bool move(int row, int col);
};


#endif //CHESS_QUEEN_H
