/*C++ preprocessor directive  that serves as an include guard,
to prevent a header file from being included more than once.*/
#pragma once

//including necessary header files
#include <bits/stdc++.h>

//enumerating pieces & colors for better code readability.
enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

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

class Board
{

}