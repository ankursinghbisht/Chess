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


//defining printboard, to print the board wrt to the current location of pieces stored in matrix names Square

void Board::printBoard()
{
    cout << "   y: 0  1  2  3  4  5  6  7 \n x:\n";

    for (int i = 0;i < 8;++i)
    {
        cout << " " << i << " ";
        for (int j = 0;j < 8;++j)
        {
            Piece p = sq[i][j].getPiece();
            Color c = setSquare[i][j].getColor();

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

//defining doMove function to accept user input to move one piece at at time & checking if move mentioned is possible or not
bool Board::doMove()
{
    int x1, x2, y1, y2;
    bool stop = false;

    while (!stop)
    {
        if (turn == WHITE)
            cout << "White's turn\n";
        else
            cout << "Black's turn\n";

        cout << "Type your move as 4 individual numbers consisting co-ordinates of Piece you want to move , following it's target location \n";
        cout << "Example if a pawn is at location (0,1) & we want to move it to (0,2), type 0 1 0 2\n";
        cin >> x1 >> y1 >> x2 >> y2;

        if (getSquare(x1, y1)->getColor() == turn)
        {
            if (makeMove(x1, y1, x2, y2) == false)
                cout << "Invalid move, Try again.\n";
            else
                stop = true;
        }
        else
            cout << "That's an invalid Piece to move. Please try again\n";
    }

    /*input is taken, and here we check if piece directly attacks the kingif yes, game is won by the attacker
    (this isn't acutal rule of chess, this is initial phase of testing of proper functioning of chess game.)*/
    if (getSquare(x2, y2)->getPiece == KING)
    {
        if (getSquare(x1, y1)->getColor() == WHITE)
        {
            cout << "\n WHITE wins.\n";
            return false;
        }
        else
        {
            cout << "BLACK wins.\n";
            return false;
        }
    }

    //code to alternate turns b/w black & white
    if (turn == BLACK)
        turn = WHITE;
    else
        turn = BLACK;
    return true;

}

//code to set initial pieces while starting the game

void Board::setBoard()
{
    //Setting up white & black pieces
    sq[0][0].setPieceAndColor(ROOK, WHITE);
    sq[1][0].setPieceAndColor(KNIGHT, WHITE);
    sq[2][0].setPieceAndColor(BISHOP, WHITE);
    sq[3][0].setPieceAndColor(QUEEN, WHITE);
    sq[4][0].setPieceAndColor(KING, WHITE);
    sq[5][0].setPieceAndColor(BISHOP, WHITE);
    sq[6][0].setPieceAndColor(KNIGHT, WHITE);
    sq[7][0].setPieceAndColor(ROOK, WHITE);

    sq[0][7].setPieceAndColor(ROOK, BLACK);
    sq[1][7].setPieceAndColor(KNIGHT, BLACK);
    sq[2][7].setPieceAndColor(BISHOP, BLACK);
    sq[3][7].setPieceAndColor(QUEEN, BLACK);
    sq[4][7].setPieceAndColor(KING, BLACK);
    sq[5][7].setPieceAndColor(BISHOP, BLACK);
    sq[6][7].setPieceAndColor(KNIGHT, BLACK);
    sq[7][7].setPieceAndColor(ROOK, BLACK);

    for (int i = 0; i < 8; i++)
    {
        sq[i][1].setPieceAndColor(PAWN, WHITE);
        sq[i][6].setPieceAndColor(PAWN, BLACK);
    }

    //setting up empty spaces
    for (int i = 2;i < 6;++i)
    {
        for (int j = 0;j < 8;++j)
            sq[j][i].setpieceAndColor(EMPTY, NONE);
    }

    //defining location of each piece in Board class instance
    for (int i = 0;i < 8;++i)
    {
        for (int j = 0;j < 8;++j)
        {
            sq[i][j].setX(i);
            sq[i][j].setY(j);
        }
    }
}

//defining playgame function to print board with each round of play 
bool Board::playGame()
{
    system("cls");
    printBoard();
    return doMove();
}

