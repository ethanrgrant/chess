//
// Created by Ethan Grant on 12/16/2017.
//

#include "Space.h"
const string Space::getValue() const{
    if(isOccupied()){
        return piece->type();
    }
    return " ";
}

bool Space::isOccupied() const{
    if(piece){
        return true;
    } else{
        return false;
    }
}

// add ownership of piece to this pointer
void Space::addPiece(unique_ptr<Piece>& newPiece){
    piece = std::move(newPiece);

}

// Transfer ownership to the refrence
void Space::removePiece(unique_ptr<Piece>& removedPiece){
    removedPiece = std::move(piece);
}

void Space::deletePiece(){
    piece.reset();
}