#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class UglyNumberII {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n);
        uglyNums[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; ++i) {
            uglyNums[i] = min(2 * uglyNums[a], min(3 * uglyNums[b], 5 * uglyNums[c]));
            a += 2 * uglyNums[a] == uglyNums[i];
            b += 3 * uglyNums[b] == uglyNums[i];
            c += 5 * uglyNums[c] == uglyNums[i];
        }
        return uglyNums.back();
    }
};
