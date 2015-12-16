#include <vector>

using std::vector;

class Combinations {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0)
            return vector<vector<int>>();
        vector<vector<int>> result;
        vector<int> cur;
        combinations(result, cur, 1, n, k);
        return result;
    }

private:
    void combinations(vector<vector<int>> &result, vector<int> &cur, int start, int end, int k) {
        if (k == 0) {
            result.push_back(cur);
            return;
        }
        for (int i = start; i <= end - k + 1; ++i) {
            cur.push_back(i);
            combinations(result, cur, i + 1, end, k - 1);
            cur.pop_back();
        }
    }
};
