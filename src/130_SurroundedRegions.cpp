#include <vector>
#include <utility>
#include <stack>

using std::vector;
using std::pair;
using std::make_pair;
using std::stack;

class SurroundedRegions {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size(), n = board[0].size();
        stack<pair<int, int>> path;
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O')
                path.push(make_pair(0, i));
            if (board[m - 1][i] == 'O')
                path.push(make_pair(m - 1, i));
        }
        for (int i = 1; i < m - 1; ++i) {
            if (board[i][0] == 'O')
                path.push(make_pair(i, 0));
            if (board[i][n - 1] == 'O')
                path.push(make_pair(i, n - 1));
        }
        while (!path.empty()) {
            int i = path.top().first, j = path.top().second;
            path.pop();
            board[i][j] = 'N';
            if (i > 0 && board[i - 1][j] == 'O')
                path.push(make_pair(i - 1, j));
            if (j < n - 1 && board[i][j + 1] == 'O')
                path.push(make_pair(i, j + 1));
            if (i < m - 1 && board[i + 1][j] == 'O')
                path.push(make_pair(i + 1, j));
            if (j > 0 && board[i][j - 1] == 'O')
                path.push(make_pair(i, j - 1));
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                switch(board[i][j]) {
                    case 'O' : board[i][j] = 'X'; break;
                    case 'N' : board[i][j] = 'O'; break;
                }
            }
        }
    }
};
