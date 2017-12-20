//
// Created by Ethan Grant on 12/16/2017.
//

#include <iostream>
#include "board.h"

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