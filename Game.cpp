//
// Created by Ethan Grant on 12/16/2017.
//

#include <iostream>
#include "Game.h"
void gameMove(Board& gameBoard, bool curColor) {
    cout << "Input row and column number of piece to move" << endl;
    bool validPiece = false;
    while(!validPiece){
        int row, column;
        cin >> row;
        cin >> column;
        Space selectedSpace;
        gameBoard.getSpace(selectedSpace, row, column);
        if(selectedSpace.isOccupied &&
           (selectedSpace.color == true && Space::WHITE ) &&
           (selectedSpace.color == false && Space::BLACK )){
            validPiece = true;
        } else{
            cout << "Row / column doesn't correspond to a valid piece try again" << endl;
        }
    }

}

bool Game::playGame(){
    Board gameBoard;
    gameBoard.printBoard();
    while(!isCheckmate){
        gameMove(gameBoard, curColor);
    }
}
