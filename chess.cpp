#include "chess.h"
using namespace std;




//states class Square's  functions body
Square::Square()
{
    piece = EMPTY;
    color = NONE;
}

void Square::setSpace(Square* space)
{
    color = space->getColor();
    piece = space->getPiece();
}

void Square::setEmpty()
{
    color = NONE;
    piece = EMPTY;
}

Piece Square::getPiece()
{
    return piece;
}

Color Square::getColor()
{
    return color;
}

void Square::setpieceAndColor(Piece p, Color c)
{
    piece = p;
    color = c;
}


//defining class Board's function body

void Board::printBoard()
{
    cout << "   y: 0  1  2  3  4  5  6  7 \n x:\n";

    for (int i = 0;i < 8;++i)
    {
        cout << " " << i << " ";
        for (int j = 0;j < 8;++j)
        {
            Piece p = Square[i][j].getPiece();
            Color c = Square[i][j].getColor();

            switch (p)
            {
            case KING:
                (c == WHITE) ? cout << "K" : cout << "k";
                break;
            case QUEEN:
                (c == WHITE) ? cout << "Q" : cout << "q";
                break;
            case BISHOP:
                (c == WHITE) ? cout << "B" : cout << "b";
                break;
            case KNIGHT:
                (c == WHITE) ? cout << "H" : cout << "h";
                break;
            case ROOK:
                (c == WHITE) ? cout << "R" : cout << "r";
                break;
            case PAWN:
                (c == WHITE) ? cout << "P" : cout << "p";
                break;
            case EMPTY:
                cout << " \21 ";
                break;
            default:
                cout << "XXX";
                break;
            }

        }
        cout << "\n";
    }

}