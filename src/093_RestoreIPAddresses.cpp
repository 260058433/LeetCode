#include <vector>
#include <string>

using std::vector;
using std::string;

class RestoreIPAddresses {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return vector<string>();
        vector<string> result;
        address(result, string(), s, 0, 4);
        return result;
    }

private:
    void address(vector<string> &result, string cur, string &s, int b, int n) {
        if (n == 0) {
            cur.pop_back();
            result.push_back(cur);
            return;
        }
        int i = s.size() - b - 3 * (--n);
        i = i < 1 ? 1 : i;
        for (; i <= 3; ++i) {
            if (i <= (s.size() - b) - n && stoi(s.substr(b, i)) <= 255 && (i == 1 || s[b] != '0')) {
                address(result, cur + s.substr(b, i) + ".", s, b + i, n);
            }
        }
    }
};
