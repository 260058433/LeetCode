#include <vector>

using std::vector;

class CombinationSumIII {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> cur;
        combination(result, cur, 1, k, n);
        return result;
    }

private:
    void combination(vector<vector<int>> &result, vector<int> &cur, int num, int k, int n) {
        if (k == 0 || n == 0 || num > 9) {
            if (k == 0 && n == 0)
                result.push_back(cur);
            return;
        }
        cur.push_back(num);
        combination(result, cur, num + 1, k - 1, n - num);
        cur.pop_back();
        combination(result, cur, num + 1, k, n);
    }
};
