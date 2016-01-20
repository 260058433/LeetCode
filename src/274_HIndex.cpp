#include <vector>

using std::vector;

class HIndex {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        vector<int> counts(n + 1);
        for (int i = 0; i < n; ++i)
            if (citations[i] >= n)
                ++counts[n];
            else
                ++counts[citations[i]];
        int sum = 0;
        for (int i = n; i >= 0; --i) {
            sum += counts[i];
            if (sum >= i)
                return i;
        }
    }
};
