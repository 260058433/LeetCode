#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

class TrieNode {
public:
    TrieNode() : next(26), isEnd(false) {
    }

    vector<TrieNode *> next;
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *cur = root;
        for (auto p = word.begin(); p != word.end(); ++p) {
            int i = *p - 'a';
            if (cur->next[i] == nullptr)
                cur->next[i] = new TrieNode();
            cur = cur->next[i];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode *cur = root;
        for (auto p = word.begin(); p != word.end(); ++p) {
            int i = *p - 'a';
            if (cur->next[i] == nullptr)
                return false;
            else
                cur = cur->next[i];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto p = prefix.begin(); p != prefix.end(); ++p) {
            int i = *p - 'a';
            if (cur->next[i] == nullptr)
                return false;
            else
                cur = cur->next[i];
        }
        return true;
    }

private:
    TrieNode *root;
};

class WordSearchII {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        if (board.empty() || board[0].empty())
            return vector<string>();
        Trie wordsTrie;
        for (auto p = words.begin(); p != words.end(); ++p)
            wordsTrie.insert(*p);
        unordered_set<string> result;
        string cur;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                find(result, cur, visited, board, i, j, wordsTrie);
        return vector<string>(result.begin(), result.end());
    }

private:
    void find(unordered_set<string> &result, string &cur, vector<vector<bool>> &visited, vector<vector<char>> &board, int row, int col, Trie &wordsTrie) {
        if (row < 0 || row == board.size() || col < 0 || col == board[0].size() || visited[row][col])
            return;
        cur.push_back(board[row][col]);
        if (wordsTrie.startsWith(cur)) {
            if (wordsTrie.search(cur))
                result.insert(cur);
            visited[row][col] = true;
            find(result, cur, visited, board, row - 1, col, wordsTrie);
            find(result, cur, visited, board, row, col + 1, wordsTrie);
            find(result, cur, visited, board, row + 1, col, wordsTrie);
            find(result, cur, visited, board, row, col - 1, wordsTrie);
            visited[row][col] = false;
        }
        cur.pop_back();
    }
};
