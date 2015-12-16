#include <string>

using std::string;
using std::to_string;

class MultipleStrings {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');
        for (int i = num2.size() - 1; i >= 0; --i) {
            int b = num2[i] - '0';
            int carry = 0;
            for (int j = num1.size() - 1; j >= 0; --j) {
                int a = num1[j] - '0';
                int r = a * b + carry + result[i + j + 1] - '0';
                carry = r / 10;
                r = r % 10;
                result[i + j + 1] = '0' + r;
            }
            if (carry)
                result[i] = '0' + carry;
        }
        int i = 0;
        while (i < result.size() - 1 && result[i] == '0')
            ++i;
        return result.substr(i, result.size() - i);
    }
};
