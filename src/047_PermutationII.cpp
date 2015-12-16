#include <vector>
#include <list>
#include <unordered_set>

using std::vector;
using std::list;
using std::unordered_set;

class PermutationsII {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        /*
        if (nums.empty())
            return vector<vector<int>>();
        list<list<int>> permutations(1, list<int>(1, nums[0]));
        for (int i = 1; i < nums.size(); ++i) {
            list<list<int>> tmp;
            for (auto p = permutations.begin(); p != permutations.end(); ++p) {
                list<int> line = *p;
                auto q = line.begin();
                for (int j = 0; j <= line.size(); ++j, ++q) {
                    while (q != line.end() && *q == nums[i]) {
                        ++q;
                        ++j;
                    }
                    auto t = line.insert(q, nums[i]);
                    tmp.push_back(line);
                    line.erase(t);
                }
            }
            permutations = tmp;
        }
        vector<vector<int>> result;
        for (auto p = permutations.begin(); p != permutations.end(); ++p) {
            vector<int> tmp;
            for (auto q = p->begin(); q != p->end(); ++q) {
                tmp.push_back(*q);
            }
            result.push_back(tmp);
        }
        return result;
        */
        vector<vector<int>> result;
        generatePermutations(result, nums, 0);
        return result;
    }

private:
    void generatePermutations(vector<vector<int>> &result, vector<int> &nums, int begin) {
        if (begin == nums.size()) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> appear;
        for (int i = begin; i < nums.size(); ++i) {
            if (appear.find(nums[i]) != appear.end())
                continue;
            int tmp = nums[i];
            nums[i] = nums[begin];
            nums[begin] = tmp;
            generatePermutations(result, nums, begin + 1);
            nums[begin] = nums[i];
            nums[i] = tmp;
            appear.insert(tmp);
        }
    }
};
