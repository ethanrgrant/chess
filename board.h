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

    bool isSpaceOccupied(int row, int column);

    Color getColor(int row, int col);

    void printBoard();

    bool movePiece(int inRow, int inCol, int outRow, int outCol);
private:

    void buildBoard();

    void buildRow(int rowNumn, Color color);

    void buildFilledRow(bool isPawn, int rowNum, Color color);

    array<array<Space*, 8>, 8> board;
};


#endif //CHESS_BOARD_H
