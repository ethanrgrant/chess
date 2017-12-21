//
// Created by Ethan Grant on 12/16/2017.
//

#include "Space.h"
const string Space::getValue() const{
    if(isOccupied()){
        return piece->type();
    }
    return "E";
}

bool Space::isOccupied() const{
    return color != Space::Occupation ::EMPTY;
}

void Space::removePiece(Piece& movingPiece){
    movingPiece = *piece;
    piece = NULL;
}

void Space::addPiece(Piece& newPiece){
    piece = &newPiece;
}