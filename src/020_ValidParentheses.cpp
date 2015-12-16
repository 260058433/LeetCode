#include <string>
#include <stack>

using std::string;
using std::stack;

class ValidParentheses {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parentheses.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (parentheses.empty()) {
                    return false;
                } else {
                    char left = parentheses.top();
                    parentheses.pop();
                    switch (s[i]) {
                        case ')' :
                          if (left != '(')
                              return false;
                          break;
                        case ']' :
                          if (left != '[')
                              return false;
                          break;
                        case '}' :
                          if (left != '{')
                              return false;
                          break;
                    }
                }
            }
        }
        return parentheses.empty();
    }
};
