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

public:
    TicTacToe(int boardSize) : size(boardSize), moves(0) {
        // Initialize the board with empty cells
        board.resize(size, vector<CellState>(size, CellState::Empty));
    }

    void printBoard() {
        // Print the current state of the board
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                char symbol;
                switch (board[i][j]) {
                    case CellState::X: symbol = 'X'; break;
                    case CellState::O: symbol = 'O'; break;
                    default: symbol = '.'; break;
                }
                cout << symbol << " ";
            }
            cout << endl;
        }
    }

    bool makeMove(int row, int col, CellState player) {
        // Make a move if the cell is empty
        if (board[row][col] == CellState::Empty) {
            board[row][col] = player;
            moves++;
            return true;
        }
        return false;
    }

    bool checkWin(CellState player) {
        // Check rows and columns
        for (int i = 0; i < size; ++i) {
            if (checkRow(i, player) || checkCol(i, player)) return true;
        }
        // Check diagonals
        return checkDiagonal(player) || checkAntiDiagonal(player);
    }

    bool checkRow(int row, CellState player) {
        for (int j = 0; j < size; ++j) {
            if (board[row][j] != player) return false;
        }
        return true;
    }

    bool checkCol(int col, CellState player) {
        for (int i = 0; i < size; ++i) {
            if (board[i][col] != player) return false;
        }
        return true;
    }

    bool checkDiagonal(CellState player) {
        for (int i = 0; i < size; ++i) {
            if (board[i][i] != player) return false;
        }
        return true;
    }

    bool checkAntiDiagonal(CellState player) {
        for (int i = 0; i < size; ++i) {
            if (board[i][size - 1 - i] != player) return false;
        }
        return true;
    }

    bool isBoardFull() {
        return moves == size * size;
    }

    pair<int, int> getBestMove() {
        int bestVal = numeric_limits<int>::min();
        pair<int, int> bestMove = {-1, -1};

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == CellState::Empty) {
                    board[i][j] = CellState::O;
                    int moveVal = minimax(0, false);
                    board[i][j] = CellState::Empty;

                    if (moveVal > bestVal) {
                        bestMove = {i, j};
                        bestVal = moveVal;
                    }
                }
            }
        }

        return bestMove;
    }

    int minimax(int depth, bool isMax) {
        if (checkWin(CellState::O)) return 10 - depth;
        if (checkWin(CellState::X)) return depth - 10;
        if (isBoardFull()) return 0;

        if (isMax) {
            int best = numeric_limits<int>::min();
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (board[i][j] == CellState::Empty) {
                        board[i][j] = CellState::O;
                        best = max(best, minimax(depth + 1, !isMax));
                        board[i][j] = CellState::Empty;
                    }
                }
            }
            return best;
        } else {
            int best = numeric_limits<int>::max();
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (board[i][j] == CellState::Empty) {
                        board[i][j] = CellState::X;
                        best = min(best, minimax(depth + 1, !isMax));
                        board[i][j] = CellState::Empty;
                    }
                }
            }
            return best;
        }
    }
};

int main() {
    int boardSize;
    cout << "Enter the size of the Tic Tac Toe board: ";
    cin >> boardSize;

    TicTacToe game(boardSize);

    while (true) {
        // Player X's turn
        int x, y;
        cout << "Player X's turn. Enter row and column (0-indexed): ";
        cin >> x >> y;
        if (!game.makeMove(x, y, CellState::X)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }
        game.printBoard();
        if (game.checkWin(CellState::X)) {
            cout << "Player X wins!\n";
            break;
        }
        if (game.isBoardFull()) {
            cout << "It's a draw!\n";
            break;
        }

        // Player O's turn using Minimax
        cout << "Player O's turn.\n";
        pair<int, int> bestMove = game.getBestMove();
        game.makeMove(bestMove.first, bestMove.second, CellState::O);
        game.printBoard();
        if (game.checkWin(CellState::O)) {
            cout << "Player O wins!\n";
            break;
        }
        if (game.isBoardFull()) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
