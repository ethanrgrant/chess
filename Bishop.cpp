//
// Created by Ethan Grant on 12/20/2017.
//

#include "Bishop.h"

bool Bishop::move(int row, int col){
    // diagonal move
    if(curRow-row == curCol-col){
        return true;
    }
    return false;
}

const string Bishop::type() const{
    return "B";
}