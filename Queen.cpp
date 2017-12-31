//
// Created by Ethan Grant on 12/20/2017.
//

#include "Queen.h"

bool Queen::move(int row, int col){
    // move forward or back
    if(curCol==col ){
        return true;
    }
    else if(curCol-col==curRow-row){
        return true;
    }
    return false;
}

const string Queen::type() const{
    return "Q";
}

bool Queen::attack(int row, int col){
    return true;
}