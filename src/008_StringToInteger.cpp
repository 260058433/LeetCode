#include <string>
#include <climits>

using std::string;

class StringToInteger {
public:
    int myAtoi(string str) {
        int i = 0, n = str.size();
        while (i < n && str[i] == ' ') {
            ++i;
        }
        bool negative = false;
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            negative = str[i] == '+' ? false : true;
            ++i;
        }
        long long result = 0;
        while (i < n) {
            if (str[i] < '0' || str[i] > '9')
                break;
            int num = str[i] - '0';
            result = result * 10 + num;
            if (!negative && result >= INT_MAX)
                return INT_MAX;
            else if (negative && -result <= INT_MIN)
                return INT_MIN;
            ++i;
        }
        if (negative)
            result = -result;
        return result;
    }
};
