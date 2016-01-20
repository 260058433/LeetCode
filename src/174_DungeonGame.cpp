#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class DungeonGame {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        if (dungeon.empty() || dungeon[0].empty())
            return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> cost(n);
        cost[n - 1] = max(0, -dungeon[m - 1][n - 1]);
        for (int i = n - 2; i >= 0; --i) {
            cost[i] = max(0, cost[i + 1] - dungeon[m - 1][i]);
        }
        for (int i = m - 2; i >= 0; --i) {
            cost[n - 1] = max(0, cost[n - 1] - dungeon[i][n - 1]);
            for (int j = n - 2; j >= 0; --j) {
                cost[j] = max(0, min(cost[j], cost[j + 1]) - dungeon[i][j]);
            }
        }
        if (cost[0] < 0)
            cost[0] = 0;
        return cost[0] + 1;
    }
};
