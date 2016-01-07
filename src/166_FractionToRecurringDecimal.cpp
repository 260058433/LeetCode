#include <string>
#include <unordered_map>

using std::string;
using std::to_string;
using std::unordered_map;

class FractionToRecurringDecimal {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        if (denominator == 0)
            return string();
        string result;
        if (numerator < 0 ^ denominator < 0)
            result.push_back('-');
        long long num = numerator, den = denominator;
        num = num < 0 ? -num : num;
        den = den < 0 ? -den : den;
        result += to_string(num / den);
        num %= den;
        if (num) {
            result.push_back('.');
            unordered_map<int, int> map;
            while (num) {
                if (map.find(num) != map.end()) {
                    result.insert(result.begin() + map[num], '(');
                    result.push_back(')');
                    break;
                } else {
                    map[num] = result.size();
                }
                num *= 10;
                result.push_back(num / den + '0');
                num %= den;
            }
        }
        return result;
    }
};
