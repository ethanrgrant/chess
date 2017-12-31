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

// prints the board
void Board::printBoard(){
    cout << "Printing Board" << endl;
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
    }
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
    // checks if this is an attack move
    if(isSpaceOccupied(outRow, outCol) && getColor(outRow, outCol) != getColor(inRow, inCol)){
        if(!isValidAttack(inRow, inCol, outRow, outCol))
            return false;
        else{
            if(board[inRow][inCol]->piece->attack(outRow, outCol)) {
                // put piece in pointer, delete captured piece, add new piece
                board[inRow][inCol]->removePiece(pieceToMove);
                board[outRow][outCol]->deletePiece();
                board[outRow][outCol]->addPiece(pieceToMove);
                return true;
            }
        }
    }
    else if(!isValidMovement(inRow, inCol, outRow, outCol)){
        return false;
    }
    else{
        if(board[inRow][inCol]->piece->move(outRow, outCol)) {
            // change piece pointer ownership from one space to another
            board[inRow][inCol]->removePiece(pieceToMove);
            board[outRow][outCol]->addPiece(pieceToMove);
            return true;
        }
    }
    // check if move is legal from rules of piece and move piece ownership

    return false;
}

// to check an attack you only need to check up to right before the proper space
bool Board::isValidAttack(int inRow, int inCol, int outRow, int outCol){
    if(inCol==outCol){
        return isValidRowMovement(inRow, inCol, --outRow);
    }
    else if(inRow==outRow){
        return isValidColMovement(inRow, inCol, --outCol);
    }
    else if(inRow!=outRow && inCol!=outCol){
        return isValidDiagMovement(inRow, inCol, --outRow, --outCol);
    }
    else{
        return false;
    }
}
// determines the type of movement and directs to correct helper function
bool Board::isValidMovement(int inRow, int inCol, int outRow, int outCol){
    if(inCol==outCol){
        return isValidRowMovement(inRow, inCol, outRow);
    }
    else if(inRow==outRow){
        return isValidColMovement(inRow, inCol, outCol);
    }
    else if(inRow!=outRow && inCol!=outCol){
        return isValidDiagMovement(inRow, inCol, outRow, outCol);
    }
    else{
        return false;
    }
}

// checks if all intervening spaces between (inRow,inCol) and (outRow, inCol) are empty
bool Board::isValidRowMovement(int inRow, int inCol, int outRow){
    cout << "checking if movement between rows is valid" << endl;
    if(inRow<outRow){
        for(int i=inRow+1; i<=outRow; i++){
            cout << " checking space (" << i << "," << inCol << ")" <<endl;
            if(isSpaceOccupied(i, inCol)){
                cout << "space (" << i << "," << inCol << ") is occupied" <<endl;
                return false;
            }
        }
    }
    else if(inRow>outRow){
        for(int i=inRow-1; i>=outRow; i--){
            cout << " checking space (" << i << "," << inCol << ")" <<endl;
            if(isSpaceOccupied(i, inCol)){
                cout << "space (" << i << "," << inCol << ") is occupied" << endl;
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}

// movement along a column
bool Board::isValidColMovement(int inRow, int inCol, int outCol){
    // for black moving down the board
    cout << "checking column movement" << endl;
    if(inCol<outCol){
        for(int curCol=inCol; curCol<=outCol; curCol++){
            if(isSpaceOccupied(inRow, curCol)){
                return false;
            }
        }
    }
    // for black moving down the board
    else if(inCol>outCol){
        for(int curCol=inCol; curCol>=outCol; curCol--){
            if(isSpaceOccupied(inRow, curCol)){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}

// TODO implement diag testing
bool Board::isValidDiagMovement(int inRow, int inCol, int outRow, int outCol){
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