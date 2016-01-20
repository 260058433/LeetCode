#include <vector>
#include <string>

using std::vector;
using std::string;
using std::stoi;

class DifferentWaysToAddParentheses {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> v1 = diffWaysToCompute(input.substr(0, i));
                vector<int> v2 = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
                for (auto p = v1.begin(); p != v1.end(); ++p)
                    for (auto q = v2.begin(); q != v2.end(); ++q)
                        switch (input[i]) {
                            case '+' : result.push_back(*p + *q); break;
                            case '-' : result.push_back(*p - *q); break;
                            case '*' : result.push_back(*p * *q); break;
                        }
            }
        }
        if (result.empty())
            result.push_back(stoi(input));
        return result;
    }
};
