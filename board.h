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

    bool movePiece(Space& inspace, Space& outSpace);
private:

    void buildBoard();

    void buildRow(int rowNumn, Piece::Color color);

    void buildFilledRow(bool isPawn, int rowNum, Piece::Color color);

    array<array<Space*, 8>, 8> board;
};


#endif //CHESS_BOARD_H
