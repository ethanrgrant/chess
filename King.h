//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <string>
#include "Piece.h"

class King: public Piece {

public:
    King(Color color_, int row, int col){
        color = color_;
        curRow = row;
        curCol = col;
    }
    bool move(int row, int col);
    const string type() const;
};


#endif //CHESS_KING_H
