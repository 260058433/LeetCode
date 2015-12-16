#include <vector>

using std::vector;

class Permutations {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        generatePermute(result, nums, 0);
        return result;
    }

private:
    void generatePermute(vector<vector<int>> &result, vector<int> &nums, int begin) {
        if (begin == nums.size())
            result.push_back(nums);
        for (int i = begin; i < nums.size(); ++i) {
            int tmp = nums[i];
            nums[i] = nums[begin];
            nums[begin] = tmp;
            generatePermute(result, nums, begin + 1);
            nums[begin] = nums[i];
            nums[i] = tmp;
        }
    }
};
