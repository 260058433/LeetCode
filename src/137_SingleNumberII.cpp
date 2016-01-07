#include <vector>

using std::vector;

class SingleNumberII {
public:
    int singleNumber(vector<int> &nums) {
        int one = 0, two = 0;
        for (int i = 0; i < nums.size(); ++i) {
            one = nums[i] & ~two ^ one;
            two = nums[i] & ~one ^ two;
        }
        return one | two;
    }
};
