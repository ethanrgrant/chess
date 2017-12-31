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
        // check if space is occupied and color of piece is correct
        if(gameBoard.isSpaceOccupied(inRow, inCol)){
            if(gameBoard.getColor(inRow, inCol)==curColor) {
                int outRow, outCol;
                while (!validToPiece) {
                    cout << "input spot to move to" << endl;
                    cin >> outRow;
                    cin >> outCol;
                    if (gameBoard.movePiece(inRow, inCol, outRow, outCol)) {
                        validToPiece = true;
                        validFromPiece = true;
                    } else {
                        cout << "The spot to move to was not valid" << endl;
                    }
                }
            }
            else{
                cout << "The piece selected is not the correct color" << endl;
            }
        } else{
            cout << "There is no piece on the selected space" << endl;
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