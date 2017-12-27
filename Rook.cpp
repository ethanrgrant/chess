//
// Created by Ethan Grant on 12/20/2017.
//

#include "Rook.h"
bool Rook::move(int row, int col){
    if(curRow == row || curCol == col){
        return true;
    }
    return false;
}

const string Rook::type() const{
    return "R";
}