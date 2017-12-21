//
// Created by Ethan Grant on 12/16/2017.
//

#include <iostream>
#include "board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

// supplies reference to space
void Board::getSpace(Space& space, int row, int column){
    space = *board[row][column];
}

// prints the board
void Board::printBoard(){
    cout << "Printing Board" << endl;
    for(const auto& row: board){
        for(const auto& space: row){
            cout << space->getValue() << "\t";
        }
        cout << endl;
    }
}

// Private Functions

void Board::buildBoard(){
    //build black side
    for(int i = 0; i<8; i++){
        if(i==0){
            buildRow(i, Piece::Color::BLACK);
        }
        else if(i==1){
            buildFilledRow(true, i, Piece::Color::BLACK);
        }
        else if(i==7){
            buildRow(i, Piece::Color::WHITE);
        }
        else if(i==6){
            buildFilledRow(true, i, Piece::Color::WHITE);
        }
        else{
            buildFilledRow(false, i, Piece::Color::WHITE);
        }
    }

}

bool Board::movePiece(Space& inSpace, Space& outSpace){
    Piece * pieceToMove;
    inSpace.removePiece(*pieceToMove);
    outSpace.addPiece(*pieceToMove);
    return true;
}

void Board::buildFilledRow(bool isPawn, int rowNum, Piece::Color color){
    for(int i = 0; i < 8; i++){
        if(isPawn){
            Piece *pawn = new Pawn(color);
            board[rowNum][i] = new Space(rowNum, i, *pawn);
        }
        else{
            board[rowNum][i] = new Space(rowNum, i);
        }
    }
}

void Board::buildRow(int rowNum, Piece::Color color){
    cout << "building row" << endl;
    Piece *rook1 = new Rook(color);
    board[rowNum][0] = new Space(rowNum, 0, *rook1);
    Piece *rook2 = new Rook(color);
    board[rowNum][7] = new Space(rowNum, 7, *rook2);
    Piece *knight1 = new Knight(color);
    board[rowNum][1] = new Space(rowNum, 1, *knight1);
    Piece *knight2 = new Knight(color);
    board[rowNum][6] = new Space(rowNum, 6, *knight2);
    Piece *bishop1 = new Bishop(color);
    board[rowNum][2] = new Space(rowNum, 2, *bishop1);
    Piece *bishop2 = new Bishop(color);
    board[rowNum][5] = new Space(rowNum, 5, *bishop2);
    Piece *queen = new Queen(color);  // TODO queen should be on her own color
    board[rowNum][3] = new Space(rowNum, 3, *queen);
    Piece *king = new King(color);
    board[rowNum][4] = new Space(rowNum, 4, *king);
}