#include <string>
#include <vector>
#include <climits>

using std::string;
using std::vector;
using std::to_string;
using std::stoi;

class ExpressionAddOperators {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        for (int i = 0; i < num.size(); ++i) {
            long long a = stoll(num.substr(0, i + 1));
            helper(result, num.substr(0, i + 1), num, i + 1, a, a, target);
            if (num[0] == '0')
                break;
        }
        return result;
    }

private:
    void helper(vector<string> &result, string expression, string &num, int pos, long long sign, long long cur, int target) {
        if (pos == num.size() && cur == target) {
            result.push_back(expression);
            return;
        }
        long long a = 0;
        for (int i = pos; i < num.size(); ++i) {
            a = a * 10 + num[i] - '0';
            helper(result, expression + "+" + num.substr(pos, i + 1 - pos), num, i + 1, a, cur + a, target);
            helper(result, expression + "-" + num.substr(pos, i + 1 - pos), num, i + 1, -a, cur - a, target);
            helper(result, expression + "*" + num.substr(pos, i + 1 - pos), num, i + 1, sign * a, cur - sign + a * sign, target);
            if (a == 0)
                break;
        }
    }
};
