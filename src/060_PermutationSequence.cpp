#include <string>
#include <vector>

using std::string;
using std::vector;
using std::to_string;

class PermutationSequence {
public:
    string getPermutation(int n, int k) {
        if (k <= 0)
            return string();
        string result;
        vector<bool> appear(n, false);
        int num = 1;
        for (int i = 1; i <= n; ++i)
            num *= i;
        k = (k - 1) % num;
        for (int i = n; i > 0; --i) {
            num /= i;
            int nth = k / num;
            for (int i = 0, j = 0; i <= nth; ++j) {
                if (!appear[j]) {
                    if (nth == i) {
                        result = result + to_string(j + 1);
                        appear[j] = true;
                    }
                    ++i;
                }
            }
            k %= num;
        }
        return result;
    }
};
