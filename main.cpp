#include<bits/stdc++.h>
#include "headerfile.h"
using namespace std;

int main()
{
    Board board;
    string s;
    bool newgame = true;

    cout << "Welcome to Chess Game\n";
    cout << "=====================\n\n";
    cout << "Instructions:\n";
    cout << "-------------\n";
    cout << "- The game is played on an 8x8 board.\n";
    cout << "- Each player starts with 16 pieces: 1 king, 1 queen, 2 rooks, 2 knights, 2 bishops, and 8 pawns.\n";
    cout << "- The objective is to checkmate your opponent's king.\n";
    cout << "- A player's turn consists of moving one of their pieces to a different square on the board.\n";
    cout << "- Players take turns until one of them wins, or the game ends in a draw.\n\n";
    cout << "Press Enter to start the game...";
    cin.get();

    while (newgame)
    {
        board.setBoard();
        while (board.playGame());
        cout << "\n Do you want to play again?(y for yes , else for no)\n";
        cin >> s;
        if (s != "y")
            newgame = false;
    }
    return 0;
}