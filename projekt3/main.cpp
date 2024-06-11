#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "ticTacToe.cpp"
using namespace std;




int main() {
    bool playing = true;
    int boardSize;
    char playerMark;
    int toWin;
    cout << "Enter the size of the Tic Tac Toe board: ";
    cin >> boardSize;
    cout << "Pick X or O: ";
    cin >> playerMark;
    cout << "How many in a line to win: ";
    cin >> toWin;
    TicTacToe game(boardSize,playerMark,toWin);
    
    while (playing) {
        // system("cls");
        // game.printBoard();
        if(game.playerMark == CellState::X && playing == true)
            playing = game.player(&game);
            // playing = game.bot2(&game);
        if(playing == true)
            playing = game.bot(&game);
        if(game.playerMark != CellState::X && playing == true)
            playing = game.player(&game);
            // playing = game.bot2(&game);
        
        
    }

    return 0;
}
