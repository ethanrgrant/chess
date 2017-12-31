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

    Pawn(Color color_, int row, int col){
        color = color_;
        hasMoved = false;
        curRow = row;
        curCol = col;
    }
    bool move(int row, int col);
    bool attack(int row, int col);

    const string type() const;
private:
    bool hasMoved;
};


#endif //CHESS_PAWN_H
