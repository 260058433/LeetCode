#include <vector>

using std::vector;

class JumpGame {
public:
    bool canJump(vector<int> &nums) {
        if (nums.empty())
            return false;
        int longest = nums[0];
        int i = 0;
        while (longest < nums.size() - 1 && i <= longest) {
            if (longest < i + nums[i])
                longest = i + nums[i];
            ++i;
        }
        return nums.size() - 1 <= longest;
    }
};
