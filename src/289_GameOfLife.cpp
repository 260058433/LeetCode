#include<vector>

using std::vector;

class GameOfLife {
public:
    void gameOfLife(vector<vector<int>> &board) {
        if (board.empty() || board[0].empty())
            return;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int sum = 0;
                for (int k = i - 1; k <= i + 1; ++k) {
                    for (int l = j - 1; l <= j + 1; ++l) {
                        if (k < 0 || k == board.size() || l < 0 || l == board[0].size())
                            continue;
                        sum += board[k][l] & 1;
                    }
                }
                if (sum == 3 || sum == 4 && board[i][j])
                    board[i][j] |= 2;
            }
        }
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                board[i][j] >>= 1;
    }
};
