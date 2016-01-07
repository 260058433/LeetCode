#include <string>
#include <algorithm>

using std::string;
using std::reverse;

class ExcelSheetColumnNumber {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            result.push_back((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
