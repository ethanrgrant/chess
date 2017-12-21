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
        int inRow, inColumn;
        cin >> inRow;
        cin >> inColumn;
        Space inSpace;
        Space outSpace;
        gameBoard.getSpace(inSpace, inRow, inColumn);
        // check if space is empty and
        if(inSpace.isOccupied() && (inSpace.color == curColor)){
            while(!validToPiece){
                cout << "input spot to move to" << endl;
                int outRow, outColumn;
                cin >> outRow;
                cin >> outColumn;
                gameBoard.getSpace(outSpace, outRow, outColumn);
                if(!outSpace.isOccupied()){
                    validToPiece = true;
                }
            }
            validFromPiece = true;
        } else{
            cout << "Row / column doesn't correspond to a valid piece try again" << endl;
        }
        if(!gameBoard.movePiece(inSpace, outSpace)){
            cout << "Error moving validated pieces" << endl;
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
    if(curColor == Space::Occupation::BLACK){
        curColor = Space::Occupation ::WHITE;
    }else{
        curColor = Space::Occupation ::BLACK;
    }
}