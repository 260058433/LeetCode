#include <string>

using std::string;

class AddBinary {
public:
    string addBinary(string a, string b) {
        int i = a.size(), j = b.size();
        int carry = 0;
        string result;
        while (i > 0 || j > 0 || carry) {
            carry += i > 0 ? a[--i] - '0' : 0;
            carry += j > 0 ? b[--j] - '0' : 0;
            result = string(1, '0' + carry % 2) + result;
            carry = carry / 2;
        }
        return result;
    }
};
