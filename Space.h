//
// Created by Ethan Grant on 12/16/2017.
//
#include <string>
#include "Piece.h"

#ifndef CHESS_SPACE_H
#define CHESS_SPACE_H

using namespace std;

class Space {

public:

    enum Occupation{
        WHITE,
        BLACK,
        EMPTY
    };

    // constuctor for empty space
    Space(){
        color = EMPTY;
        isOccupied = false;
    }

    // constuctor for space with piece
    Space(int rowNum, int colNum, Piece& thePiece){
        row = rowNum;
        column = colNum;
        piece = &thePiece;
        isOccupied = true;
    }

    const string getValue() const;

    bool isOccupied;
    Occupation color;
    Piece* piece;
    int row;
    int column;
private:

};


#endif //CHESS_SPACE_H
