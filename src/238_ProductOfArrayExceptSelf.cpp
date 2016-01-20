#include <vector>

using std::vector;

class ProductOfArrayExceptSelf {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        /*
        int n = nums.size();
        vector<int> result(n, 1);
        for (int i = n - 2; i >= 0; --i)
            result[i] = result[i + 1] * nums[i + 1];
        int pre = 1;
        for (int i = 0; i < result.size(); ++i) {
            result[i] *= pre;
            pre *= nums[i];
        }
        return result;
        */

        int n = nums.size();
        vector<int> result(n, 1);
        int fromBegin = 1, fromEnd = 1;
        for (int i = 0; i < n; ++i) {
            result[i] *= fromBegin;
            fromBegin *= nums[i];
            result[n - i - 1] *= fromEnd;
            fromEnd *= nums[n - i - 1];
        }
        return result;
    }
};
