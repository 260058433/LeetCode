#include <vector>

using std::vector;

class TrappingRainWater {
public:
    int trap(vector<int> &height) {
        int result = 0;
        int i = 0, j = height.size() - 1;
        while (i < j && height[i] <= height[i + 1])
            ++i;
        while (i < j && height[j] <= height[j - 1])
            --j;
        while (i < j) {
            int h = height[i];
            while (i < j && height[i] <= height[j]) {
                if (height[i] < h) {
                    result = result + h - height[i];
                } else {
                    h = height[i];
                }
                ++i;
            }
            h = height[j];
            while (i < j && height[j] <= height[i]) {
                if (height[j] < h) {
                    result = result + h - height[j];
                } else {
                    h = height[j];
                }
                --j;
            }
        }
        return result;
    }
};
