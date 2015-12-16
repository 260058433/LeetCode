#include <vector>

using std::vector;

class ContainerWithMostWater {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int max = 0;
        while (i < j) {
            int h = height[i] < height[j] ? height[i] : height[j];
            if ((j - i) * h > max)
                max = (j - i) * h;
            while (i < j && height[i] <= h)
                ++i;
            while (i < j && height[j] <= h)
                --j;
        }
        return max;
    }
};
