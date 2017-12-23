//
// Created by Ethan Grant on 12/16/2017.
//

#include <iostream>
#include "Game.h"

void gameMove(Board& gameBoard, bool curColor) {
    cout << "Input row and column number of piece to move" << endl;
    bool validFromPiece = false;
    bool validToPiece = false;
    while(!validFromPiece){
        int inRow, inCol;
        cin >> inRow;
        cin >> inCol;
        // check if space is empty and
        if(gameBoard.isSpaceOccupied(inRow, inCol)){
            int outRow, outCol;
            while(!validToPiece){
                cout << "input spot to move to" << endl;
                cin >> outRow;
                cin >> outCol;
                if(!gameBoard.isSpaceOccupied(outRow, outCol)){
                    validToPiece = true;
                }
            }
            if(!gameBoard.movePiece(inRow, inCol, outRow, outCol)){
                cout << "Error moving validated pieces" << endl;
            }
            validFromPiece = true;
        } else{
            cout << "Row / column doesn't correspond to a valid piece try again" << endl;
        }
    }

}

bool Game::playGame(){
    Board gameBoard;
    while(!isCheckmate){
        gameBoard.printBoard();
        gameMove(gameBoard, curColor);
        cout << "moving" << endl;
        flipColor();
    }
}

void Game::flipColor(){
    if(curColor == Color::BLACK){
        curColor = Color::WHITE;
    }else{
        curColor = Color::BLACK;
    }
}