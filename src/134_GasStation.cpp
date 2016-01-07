#include <vector>

using std::vector;

class GasStation {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.empty() || gas.size() != cost.size())
            return -1;
        int n = gas.size();
        int i = n - 1, j = 0;
        int rem = gas[i] - cost[i];
        while (i != j) {
            while (i != j && rem >= 0) {
                rem = gas[j] - cost[j] + rem;
                ++j;
            }
            while (i != j && rem < 0) {
                --i;
                rem = gas[i] - cost[i] + rem;
            }
        }
        if (rem >= 0)
            return i;
        return -1;
    }
};
