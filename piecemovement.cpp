#include "headerfile.h"
using namespace std;

//defining movements of each pieces individually

bool Board::moveKing(Square* thisKing, Square* thatSpace)
{
    //checks if difference between start & end point should be less than or equal to 2
    // as king can't move more than one step in horizonally, vertically or diagonally
    if (abs(thatSpace->getX() - thisKing->getX()) <= 1)
    {
        if (abs(thatSpace->getY() - thisKing->getY()) <= 1)
        {
            //setting new position if valid move
            thatSpace->setSpace(thisKing);
            thisKing->setEmpty();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

bool Board::moveQueen(Square* thisQueen, Square* thatspace)
{
    //it checks if position passed are valid position w.r.t to actual chess rules
    //ie. queen can move any number of positions  vertically, horizontally or diagonally unless path is obstructed. 
    int queenX = thisQueen->getX(), queenY = thisQueen->getY(), thatX = thatspace->getX(), thatY = thatspace->getY();
    int yIncrement, xIncrement;

    bool invalid = false;
    // this checks if queen is ordered to go in straight line in horizontal axis, 
    //then step by step moving queen and checking if path is clear, else returned false
    if (queenX != thatX || queenY != thatY)
    {
        yIncrement = (thatY - queenY) / (abs(thatY - queenY));
        for (int i = queenY + yIncrement;i != thatY;i += yIncrement)
        {
            if (sq[thatX][i].getColor() != NONE)
                return false;
        }
    }
    else
    {
        //same check as above is done , but with vertical axis
        if (queenY == thatY)
        {
            int xIncrement = (thatX - queenX) / abs(thatX - queenX);
            for (int i = queenX + xIncrement;i != thatX;i += xIncrement)
            {
                if (sq[i][thatY].getColor() != NONE)
                    return false;
            }
        }
        //path check is done for diagonal movements.
        else if (abs(queenX - thatX) == abs(queenY - thatY))
        {
            xIncrement = (thatX - queenX) / (abs(thatX - queenX));
            yIncrement = (thatY - queenY) / (abs(thatY - queenY));

            for (int i = 1;i < abs(queenX - thatX);++i)
            {
                if (sq[queenX + xIncrement * i][queenY + yIncrement * i].getColor() != NONE)
                    return false;
            }
        }
        else
            return false;
    }

    //setting new position if valid move
    if (!invalid)
    {
        thatspace->setSpace(thisQueen);
        thisQueen->setEmpty();
        return true;
    }
    else
        return false;

}

bool Board::moveBishop(Square* thisBishop, Square* thatSpace)
{
    //checking if the path between initial and final position is clear for bishop to move
    //bishop moves diagonally only according to chess rules.
    int bishopX = thisBishop->getX();
    int bishopY = thisBishop->getY();
    int thatX = thatSpace->getX();
    int thatY = thatSpace->getY();
    bool invalid = false;

    Square* s;

    if (abs(bishopX - thatX) == abs(bishopY - thatY))
    {
        int xIncrement = (thatX - bishopX) / abs(bishopX - thatX);
        int yIncrement = (thatY - bishopY) / abs(bishopY - thatY);

        for (int i = 1;i < abs(bishopX - thatX);++i)
        {
            if (sq[bishopX + xIncrement * i][bishopY + yIncrement * i].getColor() != NONE)
                return false;
        }
    }
    else
        return false;

    if (invalid == false)
    {
        thatSpace->setSpace(thisBishop);
        thisBishop->setEmpty();
        return true;
    }
    else
        return false;
}


bool Board::moveKnight(Square* thisKnight, Square* thatSpace)
{
    /*checking for movement of knight, as knights move in an “L-shape”—that is,
    they can move two squares in any direction vertically followed by one square horizontally ,
    or two squares in any direction horizontally followed by one square vertically*/

    int knightX = thisKnight->getX();
    int knightY = thisKnight->getY();
    int thatX = thatSpace->getX();
    int thatY = thatSpace->getY();

    if ((abs(thatX - knightX) == 2 && abs(thatY - knightY) == 1) || (abs(thatX - knightX) == 1 && abs(thatY - knightY) == 2))
    {
        thatSpace->setSpace(thisKnight);
        thisKnight->setEmpty();
        return true;
    }
    else
        return false;
}


bool Board::moveRook(Square* thisRook, Square* thatSpace)
{
    //checks if rook can move to entered location , by checking each tile in it's way step by step
    //rook can only move in straigh lines, i.e. only horizontal or vertical axis at a time.

    int rookX = thisRook->getX();
    int rookY = thisRook->getY();
    int thatX = thatSpace->getX();
    int thatY = thatSpace->getY();
    bool invalid = false;

    if (rookX != thatX || thatY != rookY)
    {
        if (rookX == thatX)
        {
            int yIncrement = (thatY - rookY) / abs(rookY - thatY);
            for (int i = rookY + yIncrement;i != thatY;i += yIncrement)
            {
                if (sq[thatX][i].getColor() != NONE)
                    return false;
            }
        }
        else
        {
            if (rookY == thatY)
            {
                int xIncrement = (thatX - rookX) / abs(rookX - thatX);
                for (int i = rookX + xIncrement;i != thatX;i += xIncrement)
                {
                    if (sq[i][thatY].getColor() != NONE)
                        return false;
                }
            }
            else
                return false;
        }
    }

    if (invalid == false)
    {
        thatSpace->setSpace(thisRook);
        thisRook->setEmpty();
        return true;
    }
    else
    {
        cout << "\n Invalid move for rook\n";
        return false;
    }

}

bool Board::movePawn(Square* thisPawn, Square* thatSpace)
{
    //pawn has a movement of 1 step at a time, it can only move straight until blocked,
    // & can attack diagonally single step ahead.

    bool invalid = false;
    int pawnX = thisPawn->getX();
    int pawnY = thisPawn->getY();
    int thatX = thatSpace->getX();
    int thatY = thatSpace->getY();

    if (thisPawn->getColor() == WHITE)
    {
        //this check is done to check if desired location is diagonal & a black piece is available to attack
        if (pawnX == thatX && thatY == pawnY + 1 && thatSpace->getColor() == NONE)
        {
            thatSpace->setSpace(thisPawn);
            thisPawn->setEmpty();
            return true;
        }
        else
        {
            if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY && thatSpace->getColor() == BLACK)
            {
                thatSpace->setSpace(thisPawn);
                thisPawn->setEmpty();
                return true;
            }
            else
                return false;
        }
    }
    else if (thisPawn->getColor() == BLACK)
    {
        //this check is done to check if desired location is diagonal & a black piece is available to attack
        if (pawnX == thatX && thatY == pawnY - 1 && thatSpace->getColor() == NONE)
        {
            thatSpace->setSpace(thisPawn);
            thisPawn->setEmpty();
            return true;
        }
        else
        {
            if ((pawnX + 1 == thatX) || pawnX - 1 == thatX && pawnY - 1 == thatY && thatSpace->getColor() == WHITE)
            {
                thatSpace->setSpace(thisPawn);
                thisPawn->setEmpty();
                return true;
            }
            else
                return false;
        }

    }
    else
        return false;
}

