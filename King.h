//
// Created by Ethan Grant on 12/20/2017.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <string>
#include "Piece.h"

class King: public Piece {

public:
    Color color;
    King(Color color2){
        color = color2;
    }
    bool move();
    const string type() const;
};


#endif //CHESS_KING_H
