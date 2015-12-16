#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class CombinationSumII {
public:
    vector<vector<int>> combinationSumII(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> cur;
        combination(result, candidates, cur, 0, target);
        return result;
    }

private:
    void combination(vector<vector<int>> &result, vector<int> &candidates, vector<int> &cur,  int i, int target) {
        if (target == 0) {
            result.push_back(cur);
            return;
        }
        for(; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                combination(result, candidates, cur, i + 1, target - candidates[i]);
                cur.pop_back();
            } else {
                break;
            }
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                ++i;
        }
    }
};
