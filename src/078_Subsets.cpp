#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std::vector;
using std::string;
using std::sort;

class Subsets {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        /*
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> cur;
        subsets(result, cur, nums, 0);
        return result;
        */

        /*
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.push_back(vector<int>());
        for (int i = 0; i < nums.size(); ++i) {
            int n = result.size();
            for (int j = 0; j < n; ++j) {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }
        return result;
        */

        sort(nums.begin(), nums.end());
        vector<vector<int>> result(pow(2, nums.size()));
        for (int i = 0; i < nums.size(); ++i) {
            int interval = 1 << i;
            for (int j = 0; j < result.size(); ) {
                if (j & 1 << i)
                    result[j++].push_back(nums[i]);
                else
                    j += interval;
            }
        }
        return result;
    }

private:
    void subsets(vector<vector<int>> &result, vector<int> &cur, vector<int> & nums, int begin) {
        if (begin == nums.size()) {
            result.push_back(cur);
            return;
        }
        cur.push_back(nums[begin]);
        subsets(result, cur, nums, begin + 1);
        cur.pop_back();
        subsets(result, cur, nums, begin + 1);
    }
};
