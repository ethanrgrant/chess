//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include <string>
#include "Piece.h"

class Queen: public Piece {

public:
    Color color;
    Queen(Color color2){
        color = color2;
    }
    bool move();
    const string type() const;
};


#endif //CHESS_QUEEN_H
