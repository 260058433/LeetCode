#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::to_string;
using std::sort;

class Comp {
public:
    bool operator()(int first, int second) const {
        /*
        string a(to_string(first)), b(to_string(second));
        int i = 0, j = 0, m = a.size(), n = b.size();
        int num = 0;
        while (i < m || j < n) {
            if (i == m)
                i = 0;
            if (j == n)
                j = 0;
            if (b[j] < a[i])
                return true;
            else if (a[i] < b[j])
                return false;
            ++i;
            ++j;
        }
        return false;
        */

        string a(to_string(first)), b(to_string(second));
        return a + b > b + a;
    }
};

class LargestNumber {
public:
    string largestNumber(vector<int> &nums) {
        if (nums.empty())
            return string();
        string result;
        sort(nums.begin(), nums.end(), Comp());
        if (nums[0] == 0)
            return "0";
        for (auto p = nums.begin(); p != nums.end(); ++p)
            result += to_string(*p);
        return result;
    }
};
