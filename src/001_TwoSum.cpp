#include <vector>
#include <unordered_map>


using std::vector;
using std::unordered_map;

class TwoSum {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        int n = nums.size();
        unordered_map<int, int> ht;
        for (int i = 0; i < n; ++i) {
            int need = target - nums[i];
            if (ht.find(need) != ht.end()) {
                result.push_back(ht[need]);
                result.push_back(i + 1);
                break;
            }
            ht[nums[i]] = i + 1;
        }
        return result;
    }    
};

