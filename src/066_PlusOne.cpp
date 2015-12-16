#include <vector>

using std::vector;

class PlusOne {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += 1;
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                carry = false;
                break;
            }
        }
        if (carry) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
