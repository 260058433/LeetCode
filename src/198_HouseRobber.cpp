#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class HouseRobber {
public:
    int rob(vector<int> &nums) {
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = max(p3, p2) + nums[i];
            p3 = p2;
            p2 = p1;
            p1 = cur;
        }
        return max(p1, p2);
    }
};
