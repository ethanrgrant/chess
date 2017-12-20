//
// Created by Ethan Grant on 12/16/2017.
//

#include <string>
#include "Piece.h"

const char * Piece::colorText( Color color )
{
    switch(color){
        case(WHITE): return "WHITE";
        case(BLACK): return "BLACK";
    }
}