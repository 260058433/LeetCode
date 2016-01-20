#include <string>

using std::string;

class BasicCalculatorII {
public:
    int calculate(string s) {
        int result = 0;
        int cur = 0, pre = 0, sign = 1;
        char preOperator = '+';
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + s[i] - '0';
            } else {
                if (preOperator == '*')
                    cur = pre * cur;
                else if (preOperator == '/')
                    cur = pre / cur;
                if (s[i] == '+' || s[i] == '-') {
                    result += sign * cur;
                    sign = s[i] == '+' ? 1 : -1;
                    pre = 0;
                } else if (s[i] == '*' || s[i] == '/') {
                    pre = cur;
                }
                preOperator = s[i];
                cur = 0;
            }
        }
        if (preOperator == '*')
            cur = pre * cur;
        else if (preOperator == '/')
            cur = pre / cur;
        result += cur * sign;
        return result;
    }
};
