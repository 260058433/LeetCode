#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class ValidSudoku {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty() || board.size() != 9 || board[0].size() != 9)
            return false;
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> appear;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                } else if (appear.find(board[i][j]) != appear.end()) {
                    return false;
                } else {
                    appear.insert(board[i][j]);
                }
            }
            appear.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue;
                } else if (appear.find(board[j][i]) != appear.end()) {
                    return false;
                } else {
                    appear.insert(board[j][i]);
                }
            }
            appear.clear();
            for (int j = 0; j < 9; ++j) {
                int k = (i / 3) * 3 + j / 3, l = j % 3 + 3 * (i % 3);
                if (board[k][l] == '.') {
                    continue;
                } else if (appear.find(board[k][l]) != appear.end()) {
                    return false;
                } else {
                    appear.insert(board[k][l]);
                }
            }
        }
        return true;
    }
};
