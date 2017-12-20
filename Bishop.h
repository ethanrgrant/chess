//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"

using namespace std;

class Bishop: public Piece {

public:

    Color color;
    Bishop(Color color2){
        color = color2;
    }
    bool move();
    const string type() const;
};


#endif //CHESS_BISHOP_H
