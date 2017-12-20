//
// Created by Ethan Grant on 12/16/2017.
//
#include <vector>
#include <array>
#include "Space.h"
#include "pawn.h"
#include "Piece.h"

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
using namespace std;
class Board {

public:

    // defines staritng position
    Board()
    {
        buildBoard();
    }

    void getSpace(Space& space, int row, int column);

    void printBoard();

private:

    void buildBoard(){
        //build black side
        // TODO remove magic numbers
        buildRow(0, Piece::Color::BLACK);
        for(int i = 0; i<8; i++) {
            Piece *pawn = new Pawn(Piece::Color::BLACK);
            board[1][i] = new Space(1, i, *pawn);
        }
        buildRow(8, Piece::Color::WHITE);
        for(int i = 0; i<8; i++) {
            Piece *pawn = new Pawn(Piece::Color::WHITE);
            board[7][i] = new Space(7, i, *pawn);
        }
    }

    void buildRow(int rowNum Piece::Color color){
        Piece *rook1 = new Rook(color);
        board[rowNum][0] = new Space(rowNum, 0, *rook1);
        Piece *rook2 = new Rook(color);
        board[rowNum][0] = new Space(rowNum, 7, *rook2);
        Piece *knight1 = new Knight(color);
        board[rowNum][0] = new Space(rowNum, 1, *knight1);
        Piece *knight2 = new Knight(color);
        board[rowNum][0] = new Space(rowNum, 6, *knight2);
        Piece *bishop1 = new Bishop(color);
        board[rowNum][0] = new Space(rowNum, 2, *bishop1);
        Piece *bishop2 = new Bishop(color);
        board[rowNum][0] = new Space(rowNum, 5, *bishop2);
        Piece *queen = new Queen(color);  // TODO queen shoudl be on her own color
        board[rowNum][0] = new Space(rowNum, 3, *queen);
        Piece *king = new King(color);
        board[rowNum][0] = new Space(rowNum, 4, *king);
    }
    array<array<Space*, 8>, 8> board;
};


#endif //CHESS_BOARD_H
