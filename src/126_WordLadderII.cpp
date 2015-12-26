#include <string>
#include <unordered_set>
#include <vector>
#include <deque>

using std::string;
using std::unordered_set;
using std::vector;
using std::deque;

class WordLadderII {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> result;
        deque<vector<string>> path;
        path.push_back(vector<string>{beginWord});
        wordList.erase(beginWord);
        wordList.insert(endWord);
        unordered_set<string> appear;
        while (!path.empty()) {
            int n = path.size();
            for (int i = 0; i < n; ++i) {
                string cur = path.front().back();
                if (cur == endWord)
                    result.push_back(path.front());
                if (!result.empty()) {
                    path.pop_front();
                    continue;
                }
                for (int j = 0; j < cur.size(); ++j) {
                    char c = cur[j];
                    for (int k = 0; k < 26; ++k) {
                        cur[j] = 'a' + k;
                        if (wordList.find(cur) != wordList.end()) {
                            path.push_back(path.front());
                            path.back().push_back(cur);
                            appear.insert(cur);
                        }
                    }
                    cur[j] = c;
                }
                path.pop_front();
            }
            if (!result.empty())
                break;
            for (auto p = appear.begin(); p != appear.end(); ++p)
                wordList.erase(*p);
            appear.clear();
        }
        return result;
    }
};
