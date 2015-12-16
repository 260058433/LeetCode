#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class CombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combination(candidates, 0, target);
    }

private:
    vector<vector<int>> combination(vector<int> &candidates, int i, int target) {
        vector<vector<int>> result;
        for (; i < candidates.size(); ++i) {
            if (candidates[i] < target) {
                vector<vector<int>> tmp = combination(candidates, i, target - candidates[i]);
                for (int j = 0; j < tmp.size(); ++j) {
                    vector<int> line;
                    line.push_back(candidates[i]);
                    line.insert(line.end(), tmp[j].begin(), tmp[j].end());
                    result.push_back(line);
                }
            } else {
                if (candidates[i] == target)
                    result.push_back(vector<int>(1, target));
                break;
            }
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                ++i;
        }
        return result;
    }
};
