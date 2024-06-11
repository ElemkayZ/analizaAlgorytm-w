#include "ticTacToe.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

    void TicTacToe::printBoard() {
        // Print the current state of the board
        printf("[ ]  ");
        for (int i = 0; i < size; i++)
        {
            printf("[%d]",i);
        }
        printf("\n\n");
        for (int i = 0; i < size; ++i) {
            printf("[%d]  ",i);
            for (int j = 0; j < size; ++j) {
                char symbol;
                cout << "[";
                switch (board[i][j]) {
                    case CellState::X: symbol = 'X'; break;
                    case CellState::O: symbol = 'O'; break;
                    default: symbol = '.'; break;
                }
                cout << symbol << "]";
            }
            cout << endl;
        }
        printf("\n\n\n");
    }

    bool TicTacToe::makeMove(int row, int col, CellState player) {
        // Make a move if the cell is empty
        if (board[row][col] == CellState::Empty) {
            board[row][col] = player;
            moves++;
            return true;
        }
        return false;
    }

    int TicTacToe::checkWin() {
        // Check rows
        for (int i = 0; i < size; ++i) {
            int playerCount = 0, botCount = 0;
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == playerMark) {
                    playerCount++;
                    botCount = 0;
                } else if (board[i][j] == botMark) {
                    botCount++;
                    playerCount = 0;
                } else {
                    playerCount = 0;
                    botCount = 0;
                }
                if (playerCount == toWin) return 1;
                if (botCount == toWin) return -1;
            }
        }

        // Check columns
        for (int j = 0; j < size; ++j) {
            int playerCount = 0, botCount = 0;
            for (int i = 0; i < size; ++i) {
                if (board[i][j] == playerMark) {
                    playerCount++;
                    botCount = 0;
                } else if (board[i][j] == botMark) {
                    botCount++;
                    playerCount = 0;
                } else {
                    playerCount = 0;
                    botCount = 0;
                }
                if (playerCount == toWin) return 1;
                if (botCount == toWin) return -1;
            }
        }

        // Check main diagonals
        for (int i = 0; i <= size - toWin; ++i) {
            for (int j = 0; j <= size - toWin; ++j) {
                int playerCount = 0, botCount = 0;
                for (int k = 0; k < toWin; ++k) {
                    if (board[i + k][j + k] == playerMark) {
                        playerCount++;
                        botCount = 0;
                    } else if (board[i + k][j + k] == botMark) {
                        botCount++;
                        playerCount = 0;
                    } else {
                        playerCount = 0;
                        botCount = 0;
                    }
                    if (playerCount == toWin) return 1;
                    if (botCount == toWin) return -1;
                }
            }
        }

        // Check anti-diagonals
        for (int i = 0; i <= size - toWin; ++i) {
            for (int j = toWin - 1; j < size; ++j) {
                int playerCount = 0, botCount = 0;
                for (int k = 0; k < toWin; ++k) {
                    if (board[i + k][j - k] == playerMark) {
                        playerCount++;
                        botCount = 0;
                    } else if (board[i + k][j - k] == botMark) {
                        botCount++;
                        playerCount = 0;
                    } else {
                        playerCount = 0;
                        botCount = 0;
                    }
                    if (playerCount == toWin) return 1;
                    if (botCount == toWin) return -1;
                }
            }
        }

        return 0;
    }   


    bool TicTacToe::isBoardFull() {
        return moves == size * size;
    }

    pair<int, int> TicTacToe::getBestMove() {
        int current;
        int best = numeric_limits<int>::max();
        pair<int, int> currentPoint = {-1, -1};
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == CellState::Empty) {
                    board[i][j] = botMark;
                    int current = minimax(MAX_DEPTH,-best,best, true);
                    board[i][j] = CellState::Empty;
                    if (current < best) {
                        currentPoint = {i, j};
                        best = current;
                    }
                }
            }
        }

        return currentPoint;
    }

    int TicTacToe::minimax(int depth, int alpha, int beta, bool isMax) {
        int gameState = checkWin();
        if (gameState != 0 || depth == 0) {
        // if (gameState == 1) return 1 - depth;   // Player win
        // if (gameState == -1) return depth - 1;  // Bot win
        return gameState;
        }
        if(isBoardFull()){
            return 0;
        }

        if (isMax) {
            int max = -std::numeric_limits<int>::max();
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (board[i][j] == CellState::Empty) {
                        board[i][j] = playerMark;
                        max = std::max(max,minimax(depth - 1, alpha, beta, false));
                        board[i][j] = CellState::Empty;
                        alpha = std::max(alpha, max);
                        if (beta <= alpha)
                            return alpha; // Alpha-beta pruning
                    }
                }
            }
            return max;
        } 
        else {
            int min = std::numeric_limits<int>::max();
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (board[i][j] == CellState::Empty) {
                        board[i][j] = botMark;
                        min = std::min(min,minimax(depth - 1, alpha, beta, true));
                        board[i][j] = CellState::Empty;
                        beta = std::min(beta, min);
                        if (beta <= alpha)
                            return beta; // Alpha-beta pruning
                    }
                }
            }
            return min;
        }
    }
    bool TicTacToe::bot(TicTacToe*game){
        if (game->checkWin()==-1) {
            cout << "Bot wins!\n";
            return false;
        }
        if (game->checkWin()==1) {
            cout << "Player wins!\n";
            return false;
        }
        if (game->isBoardFull()) {
            cout << "It's a draw!\n";
            return false;
        }
        cout << "Bot turn.\n";
        pair<int, int> bestMove = game->getBestMove();
        game->makeMove(bestMove.first, bestMove.second, CellState::O);
        game->printBoard();
        
        
        return true;
    }
    bool TicTacToe::bot2(TicTacToe*game){
        if (game->checkWin()==-1) {
            cout << "Bot wins!\n";
            return false;
        }
        if (game->checkWin()==1) {
            cout << "Bot2 wins!\n";
            return false;
        }
        if (game->isBoardFull()) {
            cout << "It's a draw!\n";
            return false;
        }
        cout << "Bot2 turn.\n";
        playerMark = CellState::O;
        botMark = CellState::X;
        pair<int, int> bestMove = game->getBestMove();
        game->makeMove(bestMove.first, bestMove.second, CellState::X);
        playerMark = CellState::X;
        botMark = CellState::O;
        game->printBoard();
        
        
        return true;
    }

    bool TicTacToe::player(TicTacToe*game){
        
        if (game->checkWin()==-1) {
            cout << "Bot wins!\n";
            return false;
        }
        if (game->checkWin()==1) {
            cout << "Player wins!\n";
            return false;
        }
        if (game->isBoardFull()) {
            cout << "It's a draw!\n";
            return false;
        }
        int x, y;
        cout << "Players turn. Enter row and column (0-indexed): ";
        cin >> x >> y;
        if (!game->makeMove(x, y, CellState::X)) {
            cout << "Invalid move. Try again.\n";
            return true;
        }
        game->printBoard();
        
        
        return true;
    }