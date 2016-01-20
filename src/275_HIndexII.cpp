#include <vector>

using std::vector;

class HIndexII {
public:
    int hIndex(vector<int> &citations) {
        int i = 0, j = citations.size() - 1, n = citations.size();
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (citations[m] >= n - m)
                j = m - 1;
            else
                i = m + 1;
        }
        return n - i;
    }
};
