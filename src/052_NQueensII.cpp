#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class NQueensII {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int result = 0;
        solve(result, board, 0);
        return result;
    }

private:
    void solve(int &result, vector<string> &cur, int i) {
        int n = cur.size();
        if (i == n) {
            ++result;
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (isValid(cur, i, j)) {
                cur[i][j] = 'Q';
                solve(result, cur, i + 1);
                cur[i][j] = '.';
            }
        }
    }

    bool isValid(vector<string> &board, int i, int j) {
        int n = board.size();
        for (int k = 0; k < i; ++k) {
            if (board[k][j] == 'Q')
                return false;
            if (j - i + k >= 0 && j - i + k < n && board[k][j - i + k] == 'Q')
                return false;
            if (j + i - k >= 0 && j + i - k < n && board[k][j + i - k] == 'Q')
                return false;
        }
        return true;
    }
};

