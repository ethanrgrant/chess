//
// Created by Ethan Grant on 12/16/2017.
//

#include <string>
#include <iostream>
#include "Piece.h"

void Piece::colorText( Color color )
{
    switch(color){
        case(BLACK): std::cout << "BLACK"; break;
        case(WHITE): std::cout << "WHITE"; break;
        case(EMPTY): std::cout << "EMPTY"; break;
        default: std::cout << "UHOH";
    }
}