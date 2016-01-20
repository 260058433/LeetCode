#include <string>
#include <vector>

using std::string;
using std::vector;

struct TrieNode {
    TrieNode() : next(26), isWord(false) {}
    vector<TrieNode *> next;
    bool isWord;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *cur = root;
        for (auto p = word.begin(); p != word.end(); ++p) {
            int i = *p - 'a';
            if (cur->next[i] == nullptr)
                cur->next[i] = new TrieNode();
            cur = cur->next[i];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        return searchFrom(word, 0, root);
    }

private:
    TrieNode *root;

    bool searchFrom(string &word, int begin, TrieNode *node) {
        for (int i = begin; i < word.size(); ++i) {
            if (word[i] != '.') {
                if (node->next[word[i] - 'a'] == nullptr)
                    return false;
                else
                    node = node->next[word[i] - 'a'];
            } else {
                for (int j = 0; j < 26; ++j)
                    if (node->next[j] && searchFrom(word, i + 1, node->next[j]))
                        return true;
                return false;
            }
        }
        return node->isWord;
    }
};
