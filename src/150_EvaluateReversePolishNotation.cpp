#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::string;
using std::stack;
using std::stoi;

class EvaluateReversePolishNotation {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> operand;
        for (auto p = tokens.begin(); p != tokens.end(); ++p) {
            if (p->size() > 1 || (*p)[0] >= '0' && (*p)[0] <= '9') {
                operand.push(stoi(*p));
            } else {
                int b = operand.top();
                operand.pop();
                int a = operand.top();
                operand.pop();
                int res = 0;
                switch ((*p)[0]) {
                    case '+' : res = a + b; break;
                    case '-' : res = a - b; break;
                    case '*' : res = a * b; break;
                    case '/' : res = a / b; break;
                }
                operand.push(res);
            }
        }
        return operand.top();
    }
};
