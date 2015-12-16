#include <string>

using std::string;

class CountAndSay {
public:
    string countAndSay(int n) {
        if (n < 1)
            return string();
        string result = "1";
        for (int i = 1; i < n; ++i) {
            string tmp;
            for (int j = 0; j < result.size(); ++j) {
                int k = j;
                while (k < result.size() - 1 && result[k] == result[k + 1])
                    ++k;
                tmp.push_back('1' + k - j);
                tmp.push_back(result[j]);
                j = k;
            }
            result = tmp;
        }
        return result;
    }
};
