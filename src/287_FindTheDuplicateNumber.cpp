#include <vector>

using std::vector;

class FindTheDuplicateNumber {
public:
    int findDuplicate(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int slow = 0, fast = 0;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        slow = 0;
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
