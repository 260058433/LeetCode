#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::sort;

class SComp {
public:
    bool operator()(string &s1, string &s2) {
        return s2.compare(s1) < 0;
    }
};

class GroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, priority_queue<string, vector<string>, SComp>> map;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push(strs[i]);
        }
        vector<vector<string>> result;
        for (auto p = map.begin(); p != map.end(); ++p) {
            vector<string> tmp;
            priority_queue<string, vector<string>, SComp> q = p->second;
            while (!q.empty()) {
                tmp.push_back(q.top()); q.pop();
            }
            result.push_back(tmp);
        }
        return result;
    }
};
