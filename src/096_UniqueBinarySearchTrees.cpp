#include <vector>

using std::vector;

class UniqueBinarySearchTrees {
public:
    int numTrees(int n) {
        vector<int> count(n + 1);
        count[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                count[i] += count[j] * count[i - 1 - j];
            }
        }
        return count[n];
    }
};
