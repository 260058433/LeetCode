#include <vector>
#include <stack>

using std::vector;
using std::stack;

class LargestRectangleInHistogram {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int result = 0;
        stack<int> increase;
        for (int i = 0; i < height.size(); ++i) {
            while (!increase.empty() && height[i] < height[increase.top()]) {
                int h = height[increase.top()];
                increase.pop();
                int tmp = i;
                if (!increase.empty())
                    tmp = tmp - increase.top() - 1;
                tmp *= h;
                if (result < tmp)
                    result = tmp;
            }
            increase.push(i);
        }
        return result;
    }
};
