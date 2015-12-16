#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class SubsetsII {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> cur;
        subsets(result, cur, nums, 0);
        return result;
    }

private:
    void subsets(vector<vector<int>> &result, vector<int> &cur, vector<int> &nums, int p) {
        if (p == nums.size()) {
            result.push_back(cur);
            return;
        }
        int i = p;
        while (i < nums.size() && nums[i] == nums[p]) {
            cur.push_back(nums[i++]);
        }
        for (int j = p; j < i; ++j) {
            subsets(result, cur, nums, i);
            cur.pop_back();
        }
        subsets(result, cur, nums, i);
    }
};
