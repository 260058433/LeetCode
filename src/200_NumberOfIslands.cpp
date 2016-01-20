#include <vector>

using std::vector;

class NumberOfIslands {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    traverseIsland(grid, i, j);
                }
            }
        }
        return result;
    }

private:
    void traverseIsland(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] != '1')
            return;
        grid[x][y] = '2';
        traverseIsland(grid, x - 1, y);
        traverseIsland(grid, x, y + 1);
        traverseIsland(grid, x + 1, y);
        traverseIsland(grid, x, y - 1);
    }
};
