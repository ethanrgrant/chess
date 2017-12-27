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
bool Board::isSpaceOccupied(int row, int col){
    return board[row][col]->isOccupied();
}

Color Board::getColor(int row, int col) {
    if(board[row][col]->piece){
        return board[row][col]->piece->color;
    }
    else{
        return EMPTY;
    }
}

void print_cols(){
    std::vector<string> col_names = {"A", "B", "C", "D", "E", "F", "G", "H"};
    for(auto& col_name : col_names){
        cout << "\t" << col_name << "\t";
    }
    cout << endl;
}

inline void print_line(){
    cout << "________________________________________________________________" << endl;
}
// prints the board
void Board::printBoard(){
    cout << "Printing Board" << endl;
    //print_cols();
    //print_line();
    for(const auto& row: board){
        cout << "|\t";
        for(const auto& space: row){
            if(space->piece){
                space->piece->colorText(space->piece->color);
                cout <<  space->getValue() << "\t|\t";
            }
            else{
                cout <<  space->getValue() << "\t|\t";
            }
        }
        cout << endl;
        //print_line();
    }
    //print_cols();
}

// Private Functions

void Board::buildBoard(){
    for(int i = 0; i<8; i++){
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
            Piece* pawn = new Pawn(color, rowNum, i);
            board[rowNum][i] = new Space(rowNum, i, pawn);
        }
        else{
            board[rowNum][i] = new Space(rowNum, i);
        }
    }
}

void Board::buildRow(int rowNum, Color color){
    Piece* rook1 = new Rook(color, rowNum, 0);
    board[rowNum][0] = new Space(rowNum, 0, rook1);
    Piece* rook2 = new Rook(color, rowNum, 7);
    board[rowNum][7] = new Space(rowNum, 7, rook2);
    Piece* knight1 = new Knight(color, rowNum, 1);
    board[rowNum][1] = new Space(rowNum, 1, knight1);
    Piece* knight2 = new Knight(color, rowNum, 6);
    board[rowNum][6] = new Space(rowNum, 6, knight2);
    Piece* bishop1 = new Bishop(color, rowNum, 2);
    board[rowNum][2] = new Space(rowNum, 2, bishop1);
    Piece* bishop2 = new Bishop(color, rowNum, 5);
    board[rowNum][5] = new Space(rowNum, 5, bishop2);
    Piece* queen = new Queen(color, rowNum, 3);  // TODO queen should be on her own color
    board[rowNum][3] = new Space(rowNum, 3, queen);
    Piece* king = new King(color, rowNum, 4);
    board[rowNum][4] = new Space(rowNum, 4, king);
}