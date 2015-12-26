#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class LongestConsecutiveSequence {
public:
    int longestConsecutive(vector<int> &nums) {
        int result = 0;
        unordered_map<int, int> lengths;
        for (auto p = nums.begin(); p != nums.end(); ++p) {
            if (lengths.find(*p) != lengths.end())
                continue;
            int left = lengths.find(*p - 1) == lengths.end() ? 0 : lengths[*p - 1];
            int right = lengths.find(*p + 1) == lengths.end() ? 0 : lengths[*p + 1];
            int length = 1 + left + right;
            if (result < length)
                result = length;
            lengths[*p] = length;
            lengths[*p - left] = length;
            lengths[*p + right] = length;
        }
        return result;
    }
};
