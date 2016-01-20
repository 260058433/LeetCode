#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::sort;

class ContainsDuplicate {
public:
    bool containDuplicate(vector<int> &nums) {
        /*
        unordered_set<int> appeared;
        for (auto p = nums.begin(); p != nums.end(); ++p) {
            if (appeared.find(*p) != appeared.end())
                return true;
            appeared.insert(*p);
        }
        return false;
        */

        /*
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
        */

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};
