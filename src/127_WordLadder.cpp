#include <string>
#include <unordered_set>
#include <queue>

using std::string;
using std::unordered_set;
using std::queue;

class WrodLadder {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) {
        if (beginWord == endWord)
            return 1;
        int length = 1;
        queue<string> que;
        que.push(beginWord);
        wordList.erase(beginWord);
        while (!que.empty()) {
            ++length;
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                string cur = que.front();
                que.pop();
                for (int j = 0; j < cur.size(); ++j) {
                    char c = cur[j];
                    for (int k = 0; k < 26; ++k) {
                        cur[j] = 'a' + k;
                        if (endWord == cur)
                            return length;
                        if (wordList.find(cur) != wordList.end()) {
                            que.push(cur);
                            wordList.erase(cur);
                        }
                    }
                    cur[j] = c;
                }
            }
        }
        return 0;
    }
};
