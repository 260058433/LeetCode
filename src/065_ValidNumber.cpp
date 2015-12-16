#include <string>

using std::string;

class ValidNumber {
public:
    bool isNumber(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            ++i;
        int status = 0;
        bool point = true, exponent = true, sign = true;
        for (; i < s.size(); ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (sign) {
                    sign = false;
                } else {
                    return false;
                }
            }else if (s[i] >= '0' && s[i] <= '9') {
                if (status % 2 == 0)
                    ++status;
                sign = false;
            } else if (s[i] == '.') {
                if (point) {
                    if (status == 0)
                        status == 2;
                    if (status == 1)
                        status == 4;
                    point = false;
                    sign = false;
                } else {
                    return false;
                }
            } else if (s[i] == 'e') {
                if (exponent && (status == 1 || status == 5)) {
                    exponent = false;
                    sign = true;
                    point = false;
                    status = 0;
                } else {
                    return false;
                }
            } else {
                break;
            }
        }
        if (status == 0 || status == 2)
            return false;
        while (i < s.size() && s[i] == ' ')
            ++i;
        return i == s.size();
    }
};
