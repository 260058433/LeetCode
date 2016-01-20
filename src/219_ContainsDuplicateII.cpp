#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::unordered_set;

class ContainsDuplicateII {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        /*
        unordered_map<int, int> appear;
        for (int i = 0; i < nums.size(); ++i) {
            if (appear.find(nums[i]) != appear.end() && i - appear[nums[i]] <= k)
                return true;
            else
                appear[nums[i]] = i;
        }
        return false;
        */

        unordered_set<int> kDifference;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                kDifference.erase(nums[i - k - 1]);
            if (kDifference.find(nums[i]) != kDifference.end())
                return true;
            kDifference.insert(nums[i]);
        }
        return false;
    }
};
