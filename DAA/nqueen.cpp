#include <iostream>
#include <vector>
using namespace std;
class NQueens {
private:
    int size;
    vector<vector<bool>> board;
    int count;
public:
    NQueens() {
        cout << "Enter size of chessboard: ";
        cin >> size;
        board.resize(size, vector<bool>(size, false));
        count = 0;
    }
    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j])
                    cout << "Q ";
                else
                    cout << "X ";
            }
            cout << endl;
        }
        cout << endl;
    }
    bool isSafe(int row, int col) {
        // Check column
        for (int i = 0; i < size; i++) {
            if (board[i][col])
                return false;
        }
        // Upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j])
                return false;
        }
        // Lower-right diagonal
        for (int i = row, j = col; i < size && j < size; i++, j++) {
            if (board[i][j])
                return false;
        }

        // Upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < size; i--, j++) {
            if (board[i][j])
                return false;
        }
        // Lower-left diagonal
        for (int i = row, j = col; i < size && j >= 0; i++, j--) {
            if (board[i][j])
                return false;
        }
        return true;
    }
    void setPositionFirstQueen() {
        int row, col;
        cout << "Enter coordinates of first queen:\n";
        cout << "Enter row (1-" << size << "): ";
        cin >> row;
        cout << "Enter column (1-" << size << "): ";
        cin >> col;
        board[row - 1][col - 1] = true;
        printBoard();
    }
    void solve(int row) {
        if (row == size) {
            count++;
            cout << "Solution " << count << ":\n";
            printBoard();
            return;
        }
        bool queenAlreadyPlaced = false;
        for (int j = 0; j < size; j++) {
            if (board[row][j]) {
                queenAlreadyPlaced = true;
                break;
            }
        }
        if (queenAlreadyPlaced) {
            solve(row + 1);
            return;
        }
        for (int col = 0; col < size; col++) {
            if (isSafe(row, col)) {
                board[row][col] = true;
                solve(row + 1);
                board[row][col] = false; // Backtrack
            }
        }
    }
    void displayMessage() {
        if (count > 0)
            cout << "Solution exists for the given position of the queen." << endl;
        else
            cout << "Solution doesn't exist for the given position of the queen." << endl;
    }
};

int main() {
    NQueens solver;
    solver.setPositionFirstQueen();
    solver.solve(0);
    solver.displayMessage();
    return 0;
}
