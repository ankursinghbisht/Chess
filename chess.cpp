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
            Color c = sq[i][j].getColor();

            switch (p)
            {
            case KING:
                (c == WHITE) ? cout << " K " : cout << " k ";
                break;
            case QUEEN:
                (c == WHITE) ? cout << " Q " : cout << " q ";
                break;
            case BISHOP:
                (c == WHITE) ? cout << " B " : cout << " b ";
                break;
            case KNIGHT:
                (c == WHITE) ? cout << " H " : cout << " h ";
                break;
            case ROOK:
                (c == WHITE) ? cout << " R " : cout << " r ";
                break;
            case PAWN:
                (c == WHITE) ? cout << " P " : cout << " p ";
                break;
            case EMPTY:
                cout << " \21 ";
                break;
            default:
                cout << "Error in switch statement\n";
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
    if (getSquare(x2, y2)->getPiece() == KING)
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
    sq[0][0].setpieceAndColor(ROOK, WHITE);
    sq[1][0].setpieceAndColor(KNIGHT, WHITE);
    sq[2][0].setpieceAndColor(BISHOP, WHITE);
    sq[3][0].setpieceAndColor(QUEEN, WHITE);
    sq[4][0].setpieceAndColor(KING, WHITE);
    sq[5][0].setpieceAndColor(BISHOP, WHITE);
    sq[6][0].setpieceAndColor(KNIGHT, WHITE);
    sq[7][0].setpieceAndColor(ROOK, WHITE);

    sq[0][7].setpieceAndColor(ROOK, BLACK);
    sq[1][7].setpieceAndColor(KNIGHT, BLACK);
    sq[2][7].setpieceAndColor(BISHOP, BLACK);
    sq[3][7].setpieceAndColor(QUEEN, BLACK);
    sq[4][7].setpieceAndColor(KING, BLACK);
    sq[5][7].setpieceAndColor(BISHOP, BLACK);
    sq[6][7].setpieceAndColor(KNIGHT, BLACK);
    sq[7][7].setpieceAndColor(ROOK, BLACK);

    for (int i = 0; i < 8; i++)
    {
        sq[i][1].setpieceAndColor(PAWN, WHITE);
        sq[i][6].setpieceAndColor(PAWN, BLACK);
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

bool Board::makeMove(int x1, int y1, int x2, int y2)
{
    //checking for any errors in co-ordinates by user and calling correspoding function if co-ordinates are valid

    if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7)
    {
        cout << "One of the co-ordinate values were out of bounds\n";
        return false;
    }
    Square* source = getSquare(x1, y1);
    Square* destination = getSquare(x2, y2);

    if (source->getColor() == destination->getColor() && destination->getColor() != NONE)
    {
        cout << "Invalid Move, cannot land on your piece\n";
        return false;
    }

    //after checking any errors, searching and calling for piece user requested to move
    switch (source->getPiece())
    {
    case KING:
        return moveKing(source, destination);
        break;
    case QUEEN:
        return moveQueen(source, destination);
        break;
    case BISHOP:
        return moveBishop(source, destination);
        break;
    case KNIGHT:
        return moveKnight(source, destination);
        break;
    case ROOK:
        return moveRook(source, destination);
        break;
    case PAWN:
        return movePawn(source, destination);
        break;
    case EMPTY:
        cout << "No piece is availabe at requested location\n";
        break;

    default:
        cout << "Error in switch statement\n";
        break;
    }
    return false;
}

