#include <climits>

class DivideTwoIntegers {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        long result = 0;
        long a = dividend, b = divisor;
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        int i = 0;
        while (b << i < a)
            ++i;
        while (a != 0 && i >= 0) {
            while (i >= 0 && a < b << i)
                --i;
            if (i >= 0) {
                result += (long)1 << i;
                a -= b << i;
            }
        }
        if (dividend < 0 ^ divisor < 0)
            result = -result;
        if (result > INT_MAX)
            result = INT_MAX;
        else if (result < INT_MIN)
            result = INT_MIN;
        return result;
    }
};
