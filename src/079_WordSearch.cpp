#include <vector>
#include <string>

using std::vector;
using std::string;

class WordSearch {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
            return false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (find(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool find(vector<vector<char>> &board, string &word, int i, int j, int k) {
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] != word[k])
            return false;
        char c = board[i][j];
        board[i][j] = 0;
        if (find(board, word, i - 1, j, k + 1) || find(board, word, i, j + 1, k + 1) || find(board, word, i + 1, j, k + 1) || find(board, word, i, j - 1, k + 1))
            return true;
        board[i][j] = c;
        return false;
    }
};
