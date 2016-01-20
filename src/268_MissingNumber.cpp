#include <vector>

using std::vector;

class MissingNumber {
public:
    int missingNumber(vector<int> &nums) {
        //maybe overflow
        /*
        int sum = (nums.size() + 1) * nums.size() / 2;
        for (auto p = nums.begin(); p != nums.end(); ++p)
            sum -= *p;
        return sum;
        */

        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
            result = result ^ nums[i] ^ (i + 1);
        return result;
    }
};
