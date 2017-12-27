//
// Created by Ethan Grant on 12/17/2017.
//

#include "pawn.h"

bool Pawn::move(int row, int col){
    // forward move either 1 or 2 spots
    if(hasMoved){
        if(row==curRow && col==curCol+1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(row==curRow && (col==curCol+1 || col==curCol+2))
        {
            return true;
        }
        else{
            return false;
        }
    }
}

const string Pawn::type() const{
    return "P";
}