#include <vector>
#include <string>

using std::vector;
using std::string;

class LetterCombinationsOfAPhoneNumber {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return vector<string>();
        vector<string> result(1);
        vector<string> map{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> tmp;
            int dig = digits[i] - '0';
            for (int j = 0; j < map[dig].size(); ++j) {
                for (int k = 0; k < result.size(); ++k) {
                    string s = result[k];
                    s.push_back(map[dig][j]);
                    tmp.push_back(s);
                }
            }
            result = tmp;
        }
        return result;
    }
};
