#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_multiset;

class SubstringWithConcatenationOfAllWords {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (s.empty() || words.empty() || words[0].empty() || s.size() < words.size() * words[0].size())
            return vector<int>();
        unordered_multiset<string> keys;
        for (int i = 0; i < words.size(); ++i)
            keys.insert(words[i]);
        int l = words[0].size();
        vector<int> result;
        for (int b = 0; b < l; ++b) {
            int i = b;
            while (i <= s.size() - words.size() * l) {
                if (keys.find(s.substr(i, l)) != keys.end()) {
                    unordered_multiset<string> appeared;
                    int j = i;
                    while (j <= s.size() - l) {
                        string w = s.substr(j, l);
                        if (keys.find(w) == keys.end()) {
                            break;
                        } else if (appeared.count(w) == keys.count(w)) {
                            while (s.substr(i, l) != w) {
                                appeared.erase(appeared.find(s.substr(i, l)));
                                i += l;
                            }
                            i += l;
                        } else {
                            appeared.insert(w);
                        }
                        if (appeared.size() == keys.size()) {
                            result.push_back(i);
                            i += l;
                            appeared.erase(appeared.find(w));
                        }
                        j += l;
                    }
                    i = j;
                }
                i += l;
            }
        }
        return result;
    }
};
