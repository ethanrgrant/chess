//
// Created by Ethan Grant on 12/16/2017.
//
#include <string>
#include <iostream>
#include <bits/unique_ptr.h>
#include "Piece.h"
#include "color.h"

#ifndef CHESS_SPACE_H
#define CHESS_SPACE_H

using namespace std;

class Space {

public:

    Space(){};

    // constuctor for empty space
    Space(int rowNum, int colNum){
        row = rowNum;
        column = colNum;
        color = EMPTY;
    }

    // constuctor for space with piece
    Space(int rowNum, int colNum, Piece* thePiece){
        row = rowNum;
        column = colNum;
        piece = unique_ptr<Piece>(thePiece);
        if(thePiece->color == Color::WHITE){
            color = WHITE;
        }
        else if(thePiece->color == Color::BLACK){
            color = BLACK;
        }
        else{
            cout << "Tried to assign empty color to space with " << endl;
        }
    }

    const string getValue() const;

    bool isOccupied() const;

    void removePiece(unique_ptr<Piece>& removedPiece);

    void addPiece(unique_ptr<Piece>& newPiece);

    Color color;
    unique_ptr<Piece> piece;
    int row;
    int column;

    Space& operator=(Space&& copySpace){
        piece = std::move(copySpace.piece);
        int row = copySpace.row;
        int column = copySpace.column;
        return *this;
    }

private:

};


#endif //CHESS_SPACE_H
