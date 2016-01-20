#include <vector>
#include <string>

using std::vector;
using std::string;

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
