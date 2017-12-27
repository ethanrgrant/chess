//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"
#include <string>
using namespace std;

class Bishop: public Piece {

public:

    Bishop(Color color_, int row, int col){
        color = color_;
        curRow = row;
        curCol = col;
    }
    bool move(int row, int col);
    const string type() const;
};


#endif //CHESS_BISHOP_H
