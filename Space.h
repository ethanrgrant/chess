//
// Created by Ethan Grant on 12/16/2017.
//
#include <string>
#include <iostream>
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

    Space(){
    }

    // constuctor for empty space
    Space(int rowNum, int colNum){
        row = rowNum;
        column = colNum;
        piece = NULL;
        color = EMPTY;
    }

    // constuctor for space with piece
    Space(int rowNum, int colNum, Piece& thePiece){
        row = rowNum;
        column = colNum;
        piece = &thePiece;
        if(thePiece.color == Piece::Color::WHITE){
            color = WHITE;
        }
        else if(thePiece.color == Piece::Color::BLACK){
            color = BLACK;
        }
        else{
            cout << "Tried to assign empty color to space with " << endl;
        }
    }

    const string getValue() const;

    bool isOccupied() const;

    void removePiece(Piece& piece);

    void addPiece(Piece& piece);

    Occupation color;
    Piece* piece;
    int row;
    int column;
private:

};


#endif //CHESS_SPACE_H
