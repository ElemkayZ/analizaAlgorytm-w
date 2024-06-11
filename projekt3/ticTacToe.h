#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

enum class CellState { Empty, X, O };



class TicTacToe {
private:
    vector<vector<CellState>> board;
    int size;
    int moves;
    CellState botMark;
    int toWin;
public:
    CellState playerMark;
    const int MAX_DEPTH = 8;
    TicTacToe(int _boardSize, char _playerMark, int _toWin) : size(_boardSize), moves(0), toWin(_toWin){
        if (size < 3)
            size = 3;
        if (toWin < 2)
            toWin = 2;
        if (toWin > size)
            toWin = size;
        // Initialize the board with empty cells
        board.resize(size, vector<CellState>(size, CellState::Empty));
        if (_playerMark == 'x'){
            playerMark = CellState::X;
            botMark = CellState::O;
        }
        else if (_playerMark == 'o'){
            playerMark = CellState::O;
            botMark = CellState::X;
        }
        else {
        playerMark = CellState::X;
            botMark = CellState::O;
        }
    }

    void printBoard();
    bool makeMove(int row, int col, CellState player);
    int checkWin();
    bool isBoardFull();
    pair<int, int> getBestMove();
    int minimax(int depth, int alpha, int beta, bool isMax);
    bool bot(TicTacToe*game);
    bool bot2(TicTacToe*game);
    bool player(TicTacToe*game);
};
