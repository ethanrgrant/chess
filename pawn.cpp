//
// Created by Ethan Grant on 12/17/2017.
//

#include <iostream>
#include "pawn.h"

bool Pawn::move(int row, int col){
    // for moving up or down the board
    int num;
    if(color==BLACK) {
        num = 1;
    }
    else {
        num = -1;
    }

    // forward move either 1 or 2 spots
    if(!hasMoved && curCol==col && (curRow+num*2==row || curRow+num==row))
        return true;
    else if(curCol==col && curRow+num==row)
        return true;
    return false;

}

// TODO implement attack moves
bool Pawn::attack(int row, int col){
    return true;
}

const string Pawn::type() const{
    return "P";
}

