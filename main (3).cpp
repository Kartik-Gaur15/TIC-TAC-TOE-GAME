/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

void showBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Rows
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Columns
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Diagonal 1
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true; // Diagonal 2
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9') return false;
    return true;
}

void playMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter a number (1-9): ";
    cin >> move;

    if (move < 1 || move > 9) {
        cout << "Invalid move! Try again.\n";
        return;
    }

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Spot taken! Try again.\n";
        return;
    }

    board[row][col] = currentPlayer;
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    
    while (true) {
        showBoard();
        playMove();
        
        if (checkWin()) {
            showBoard();
            cout << "Player " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins!\n";
            break;
        }

        if (isDraw()) {
            showBoard();
            cout << "It's a draw!\n";
            break;
        }
    }
    
    return 0;
}
