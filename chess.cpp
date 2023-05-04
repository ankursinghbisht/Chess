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
                if (c == WHITE)
                    cout << "K";
                else
                    cout << "k";
                break;
            case QUEEN:
                if (c == WHITE)
                    cout << "Q";
                else
                    cout << "q";
                break;
            case BISHOP:
                if (c == WHITE)
                    cout << "B";
                else
                    cout << "b";
                break;
            case KNIGHT:
                if (c == WHITE)
                    cout << "H";
                else
                    cout << "h";
                break;
            case ROOK:
                if (c == WHITE)
                    cout << "R";
                else
                    cout << "r";
                break;
            case PAWN:
                if (c == WHITE)
                    cout << "P";
                else
                    cout << "p";
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