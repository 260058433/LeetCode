#include <vector>

using std::vector;

class MajorityElementII {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int count1 = 0, count2 = 0;
        int a, b;
        for (auto p = nums.begin(); p != nums.end(); ++p) {
            if (*p == a) {
                ++count1;
            } else if (*p == b) {
                ++count2;
            } else if (count1 == 0) {
                a = *p;
                ++count1;
            } else if (count2 == 0) {
                b = *p;
                ++count2;
            } else {
                --count1;
                --count2;
            }
        }
        count1 = 0;
        count2 = 0;
        for (auto p = nums.begin(); p != nums.end(); ++p) {
            if (a == *p)
                ++count1;
            if (b == *p)
                ++count2;
        }
        vector<int> result;
        if (count1 > nums.size() / 3)
            result.push_back(a);
        if (count2 > nums.size() / 3)
            result.push_back(b);
        return result;
    }
};
