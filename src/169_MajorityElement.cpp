#include <vector>

using std::vector;

class MajorityElement {
public:
    int majorityElement(vector<int> &nums) {
        int major = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == major) {
                ++count;
            } else {
                if (count == 0) {
                    major = nums[i];
                    count = 1;
                } else {
                    --count;
                }
            }
        }
        return major;
    }
};
