//
// Created by Ethan Grant on 12/16/2017.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <iosfwd>
#include <vector>
#include "color.h"

using namespace std;

class Piece {

public:

    void colorText( Color color );

    // this function determines whether a move is legal. Not whether it is possible
    // it is up to the board to check if there are pieces in the way.
    virtual bool move(int row, int col) = 0;
    virtual const string type() const = 0;
    virtual bool attack(int row, int col) = 0;
    Color color;
    int curRow;
    int curCol;
private:


};


#endif //CHESS_PIECE_H
