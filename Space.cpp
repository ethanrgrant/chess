//
// Created by Ethan Grant on 12/16/2017.
//

#include "Space.h"
const string Space::getValue() const{
    if(isOccupied){
        return piece->type();
    }
    return "E";
}