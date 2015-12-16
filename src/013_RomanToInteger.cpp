#include <string>

using std::string;

class RomanToInteger {
public:
    int romanToInt(string s) {
        int result = 0;
        int pre = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cur = 0;
            switch(s[i]) {
                case 'M' : cur = 1000; break;
                case 'D' : cur = 500; break;
                case 'C' : cur = 100; break;
                case 'L' : cur = 50; break;
                case 'X' : cur = 10; break;
                case 'V' : cur = 5; break;
                case 'I' : cur = 1; break;
            }
            if (pre >= cur)
                result += pre;
            else
                result -= pre;
            pre = cur;
        }
        result += pre;
        return result;
    }
};
