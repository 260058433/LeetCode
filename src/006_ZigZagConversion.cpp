#include <string>

using std::string;

class ZigZagConversion {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.size() <= numRows) {
            return s;
        }
        int i = 0;
        string result(s.size(), 0);
        int period = 2 * numRows - 2;
        for (int j = 0; j < numRows; ++j) {
            int k = j;
            while (k < s.size()) {
                result[i++] = s[k];
                k += period - 2 * j;
                if (j != 0 && j != numRows - 1 && k < s.size()) {
                    result[i++] = s[k];
                }
                k += 2 * j;
            }
        }
        return result;
    }
};
