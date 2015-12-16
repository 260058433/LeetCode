#include <string>

using std::string;

class DecodeWays {
public:
    int numDecodings(string s) {
        int t1 = 1, t2 = 1;
        if (s.empty() || s.back() == '0')
            t1 = 0;
        for (int i = s.size() - 2; i >= 0; --i) {
            int cur = t1;
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                cur += t2;
            else if (s[i] == '0')
                cur = 0;
            t2 = t1;
            t1 = cur;
        }
        return t1;
    }
};
