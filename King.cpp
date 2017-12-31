//
// Created by Ethan Grant on 12/20/2017.
//

#include "King.h"
bool King::move(int row, int col){
    if(abs(curRow-row)==1 || abs(curCol-col)==1){
        return true;
    }
    return false;
}

const string King::type() const{
    return "K";
}

bool King::attack(int row, int col){
    return true;
}