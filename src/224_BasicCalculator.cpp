#include <string>
#include <stack>

using std::string;
using std::stack;

class BasicCalculator {
public:
    int calculate(string s) {
        /*
        stack<int> operands;
        stack<char> operators;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                int a = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                    a = a * 10 + s[i++] - '0';
                operands.push(a);
            } else {
                if (s[i] == '(') {
                    operators.push(s[i]);
                    continue;
                }
                while (!operators.empty() && operators.top() != '(') {
                    int b = operands.top();
                    operands.pop();
                    int a = operands.top();
                    operands.pop();
                    switch (operators.top()) {
                        case '+' : operands.push(a + b); break;
                        case '-' : operands.push(a - b); break;
                    }
                    operators.pop();
                }
                if (s[i] == ')')
                    operators.pop();
                else
                    operators.push(s[i]);
                ++i;
            }
        }
        while (!operators.empty()) {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            switch (operators.top()) {
                case '+' : operands.push(a + b); break;
                case '-' : operands.push(a - b); break;
            }
            operators.pop();
        }
        return operands.top();
        */

        int result = 0, sign = 1;
        stack<int> tmp;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                    num = num * 10 + s[i++] - '0';
                result += sign * num;
            } else {
                if (s[i] == '+') {
                    sign = 1;
                } else if (s[i] == '-') {
                    sign = -1;
                } else if (s[i] == '(') {
                    tmp.push(result);
                    tmp.push(sign);
                    result = 0;
                    sign = 1;
                } else if (s[i] == ')') {
                    int num = result;
                    sign = tmp.top();
                    tmp.pop();
                    result = tmp.top();
                    tmp.pop();
                    result += num * sign;
                }
                ++i;
            }
        }
        return result;
    }
};
