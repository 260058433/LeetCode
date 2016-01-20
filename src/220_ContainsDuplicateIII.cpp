#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class ContainsDuplicateIII {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.empty() || k <= 0 || t < 0)
            return false;
        unordered_map<int, int> buckets;
        for (int i = 0; i < nums.size(); ++i) {
            int j = nums[i] / (t + 1) - (nums[i] < 0);
            if (buckets.find(j) != buckets.end() || buckets.find(j - 1) != buckets.end() && (long long)nums[i] - buckets[j - 1] <= t || buckets.find(j + 1) != buckets.end() && (long long)buckets[j + 1] - nums[i] <= t)
                return true;
            if (i >= k)
                buckets.erase(nums[i - k] / (t + 1) - (nums[i - k] < 0));
            buckets[j] = nums[i];
        }
        return false;
    }
};
