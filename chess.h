/*C++ preprocessor directive  that serves as an include guard,
to prevent a header file from being included more than once.*/
#pragma once

//including necessary header files
#include <bits/stdc++.h>

//enumerating pieces & colors for better code readability.
enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

//declaring class for individual pieces with their properties and functions
class Square
{
    Piece piece;
    Color color;

    int x, y;

public:


    void setSpace(Square*);
    void setEmpty();
    void setpieceAndColor(Piece, Color);

    Piece getPiece();
    Color getColor();

    void setX(int input_x)
    {
        x = input_x;
    }
    void setY(int input_y)
    {
        y = input_y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};

//setting up the chess board
class Board
{
    Square sq[8][8];
    Color turn = WHITE;

    //defining all functions required to play
    bool moveKing(Square* thisKing, Square* thatSpace);
    bool moveQueen(Square* thisQueen, Square* thatSpace);
    bool moveBishop(Square* thisBishop, Square* thatSpace);
    bool moveKnight(Square* thisKnight, Square* thatSpace);
    bool moveRook(Square* thisRook, Square* thatSpace);
    bool movePawn(Square* thisPawn, Square* thatSpace);
    bool makeMove(int x1, int y1, int x2, int y2);
    void printBoard();

public:

    Square* getSquare(int x, int y)
    {
        return &sq[x][y];
    }

    void setSquare(Square* s, int x, int y)
    {
        sq[x][y] = *s;
    }
    bool doMove();

    void setBoard();

    bool playGame();
}