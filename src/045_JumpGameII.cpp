#include <vector>

using std::vector;

class JumpGameII {
public:
    int jump(vector<int> &nums) {
        int result = 0;
        int next = 0;
        while (next + nums[next] < nums.size() - 1) {
            int n = next + nums[next];
            for (int i = next; i <= n; ++i) {
                if (next + nums[next] < i + nums[i] && nums[i] != 0)
                    next = i;
            }
            if (next + nums[next] == n)
                return -1;
            ++result;
        }
        if (next != nums.size() - 1)
            ++result;
        return result;
    }
};
