#include <iostream>
#include <vector>
using namespace std;

class NQueens {
    int n;
    vector<vector<int>> board;

public:
    NQueens(int size) {
        n = size;
        board.resize(n, vector<int>(n, 0));
    }

    // Check whether queen can be placed safely
    bool isSafe(int row, int col) {

        // Check upper column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 1)
                return false;
        }

        // Check upper left diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 1)
                return false;
        }

        // Check upper right diagonal
        for(int i=row, j=col; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 1)
                return false;
        }

        return true;
    }

    // Backtracking function
    bool solve(int row) {

        // All queens placed
        if(row == n)
            return true;

        for(int col = 0; col < n; col++) {

            if(isSafe(row, col)) {

                // Place queen
                board[row][col] = 1;

                // Recur for next row
                if(solve(row + 1))
                    return true;

                // Backtrack
                board[row][col] = 0;
            }
        }

        return false;
    }

    void display() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }
};

int main() {

    int n;

    cout << "Enter value of N: ";
    cin >> n;

    NQueens q(n);

    if(q.solve(0)) { // Start solving from the first row (row 0)
        cout << "\nSolution Exists:\n";
        q.display();
    }
    else {
        cout << "\nNo Solution Exists";
    }

    return 0;
}

/*

================ N-Queens Problem ================

Sample Input:
4

Explanation:
4 -> Size of chessboard (4x4)
Program will place 4 queens on the board such that:
- No two queens are in the same row
- No two queens are in the same column
- No two queens are on the same diagonal

Expected Output:

Solution Exists:

. Q . .
. . . Q
Q . . .
. . Q .

*/