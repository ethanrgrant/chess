//
// Created by Ethan Grant on 12/16/2017.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <iosfwd>
#include <vector>

using namespace std;

class Piece {

public:

    enum Color{
        WHITE,
        BLACK
    };

    enum PieceTypes{
        ROOK,
        KNIGHT,
        BISHOP,
        KING,
        QUEEN,
        PAWN
    };

    const char * colorText( Color color );

    virtual bool move() = 0;
    virtual const string type() const = 0;

private:
    Color color;
    int row;
    int column;

};


#endif //CHESS_PIECE_H
