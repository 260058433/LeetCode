#include <vector>

using std::vector;

class SudokuSolver {
public:
    void solveSudoku(vector<vector<char>> &board) {
        if (board.size() != 9 || board[0].size() != 9)
            return;
        solve(board, 0, 0);
    }

private:
    bool solve(vector<vector<char>> &board, int i, int j) {
        if (j == 9) {
            ++i;
            j = 0;
        }
        if (i == 9)
            return true;
        if (board[i][j] != '.') {
            return solve(board, i, j + 1);
        } else {
            for (int k = 1; k <= 9; ++k) {
                board[i][j] = '0' + k;
                if (valid(board, i, j) && solve(board, i, j + 1)) {
                    return true;
                }
            }
            board[i][j] = '.';
        }
        return false;
    }

    bool valid(vector<vector<char>> &board, int i, int j) {
        int a = (i / 3) * 3, b = (j / 3) * 3;
        for (int k = 0; k < 9; ++k) {
            if (board[i][k] == board[i][j] && k != j)
                return false;
            if (board[k][j] == board[i][j] && k != i)
                return false;
            if (board[a + k / 3][b + k % 3] == board[i][j] && a + k / 3 != i && b + k % 3 != j)
                return false;
        }
        return true;
    }
};
