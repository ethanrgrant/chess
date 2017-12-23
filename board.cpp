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
#include <memory>

// supplies reference to space
bool Board::isSpaceOccupied(int row, int column){
    return board[row][column]->isOccupied();
}

Color Board::getColor(int row, int col) {
    return board[row][col]->color;
}

// prints the board
void Board::printBoard(){
    cout << "Printing Board" << endl;
    for(const auto& row: board){
        cout << "|\t";
        for(const auto& space: row){
            cout << space->getValue() << "\t|\t";
        }
        cout << endl;
    }
}

// Private Functions

void Board::buildBoard(){
    //build black side
    for(int i = 0; i<8; i++){
        cout << i << endl;
        if(i==0){
            buildRow(i, Color::BLACK);
        }
        else if(i==1){
            buildFilledRow(true, i, Color::BLACK);
        }
        else if(i==7){
            buildRow(i, Color::WHITE);
        }
        else if(i==6){
            buildFilledRow(true, i, Color::WHITE);
        }
        else{
            buildFilledRow(false, i, Color::WHITE);
        }
    }

}

bool Board::movePiece(int inRow, int inCol, int outRow, int outCol){
    unique_ptr<Piece> pieceToMove;
    board[inRow][inCol]->removePiece(pieceToMove);
    board[outRow][outCol]->addPiece(pieceToMove);
    return true;
}


void Board::buildFilledRow(bool isPawn, int rowNum, Color color){
    cout << " building filled row" << endl;
    for(int i = 0; i < 8; i++){
        if(isPawn){
            Piece* pawn = new Pawn(color);
            board[rowNum][i] = new Space(rowNum, i, pawn);
        }
        else{
            board[rowNum][i] = new Space(rowNum, i);
        }
    }
}

void Board::buildRow(int rowNum, Color color){
    cout << "building row" << endl;
    Piece* rook1 = new Rook(color);
    board[rowNum][0] = new Space(rowNum, 0, rook1);
    Piece* rook2 = new Rook(color);
    board[rowNum][7] = new Space(rowNum, 7, rook2);
    Piece* knight1 = new Knight(color);
    board[rowNum][1] = new Space(rowNum, 1, knight1);
    Piece* knight2 = new Knight(color);
    board[rowNum][6] = new Space(rowNum, 6, knight2);
    Piece* bishop1 = new Bishop(color);
    board[rowNum][2] = new Space(rowNum, 2, bishop1);
    Piece* bishop2 = new Bishop(color);
    board[rowNum][5] = new Space(rowNum, 5, bishop2);
    Piece* queen = new Queen(color);  // TODO queen should be on her own color
    board[rowNum][3] = new Space(rowNum, 3, queen);
    Piece* king = new King(color);
    board[rowNum][4] = new Space(rowNum, 4, king);
}