cmake_minimum_required(VERSION 3.7)
project(chess)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp board.cpp board.h Space.cpp Space.h Piece.cpp Piece.h Game.cpp Game.h pawn.cpp pawn.h Bishop.cpp Bishop.h Rook.cpp Rook.h Queen.cpp Queen.h King.cpp King.h Knight.cpp Knight.h)
add_executable(chess ${SOURCE_FILES})