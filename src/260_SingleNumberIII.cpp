#include <vector>

using std::vector;

class SingleNumberIII {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int diff = 0;
        for (auto p = nums.begin(); p != nums.end(); ++p)
            diff ^= *p;
        int i = 0;
        while (!(diff & (1 << i)))
            ++i;
        int a = 0, b = 0;
        for (auto p = nums.begin(); p != nums.end(); ++p)
            if ((*p) & (1 << i))
                a ^= *p;
            else
                b ^= *p;
        return vector<int>{a, b};
    }
};
