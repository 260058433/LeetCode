#include <vector>

using std::vector;

class GrayCode {
public:
    vector<int> grayCode(int n) {
        if (n < 0)
            return vector<int>();
        vector<int> result(1);
        for (int i = 0; i < n; ++i) {
            int j = result.size();
            int pre = 1 << i;
            while (j > 0)
                result.push_back(pre + result[--j]);
        }
        return result;
    }
};
