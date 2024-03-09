#include <iostream>
#include <vector>

using namespace std;

// Function declarations
void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char currentPlayer, int row, int col);
bool checkWin(const vector<vector<char>>& board, char currentPlayer);
bool checkDraw(const vector<vector<char>>& board);
char switchPlayer(char currentPlayer);
bool playAgain();

int main() {
    // Initialize the game board
    vector<vector<char>> board(3, vector<char>(3, ' '));

    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    do {
        // Display the current state of the board
        displayBoard(board);

        // Player input
        int row, col;
        do {
            cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
            cin >> row >> col;
        } while (!makeMove(board, currentPlayer, row - 1, col - 1));

        // Check for a win
        gameWon = checkWin(board, currentPlayer);

        // Check for a draw
        gameDraw = checkDraw(board);

        // Switch players
        currentPlayer = switchPlayer(currentPlayer);

    } while (!gameWon && !gameDraw && playAgain());

    return 0;
}

// Function to display the current state of the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "Game Board:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}

// Function to make a move on the board
bool makeMove(vector<vector<char>>& board, char currentPlayer, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        cout << "Invalid move. Try again." << endl;
        return false;
    }
}

// Function to check for a win
bool checkWin(const vector<vector<char>>& board, char currentPlayer) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            return true;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            return true;
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        cout << "Player " << currentPlayer << " wins!" << endl;
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        cout << "Player " << currentPlayer << " wins!" << endl;
        return true;
    }

    return false;
}

// Function to check for a draw
bool checkDraw(const vector<vector<char>>& board) {
    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;  // The game is not a draw
            }
        }
    }

    // All spaces are filled, and no player has won
    cout << "The game is a draw!" << endl;
    return true;
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to ask if the players want to play again
bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
