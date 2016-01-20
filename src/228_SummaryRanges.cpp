#include <string>
#include <vector>

using std::string;
using std::vector;
using std::to_string;

class SummaryRanges {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        int i = 0, n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            int begin = nums[i], end = nums[i];
            while (i + 1 < n && end + 1 == nums[i + 1]) {
                ++end;
                ++i;
            }
            if (begin == end)
                result.push_back(to_string(begin));
            else
                result.push_back(to_string(begin) + "->" + to_string(end));
        }
        return result;
    }
};
