#include <vector>

using std::vector;

class Triangle {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        vector<int> sum(triangle.size());
        sum[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            sum[i] = sum[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                sum[j] = (sum[j - 1] < sum[j] ? sum[j - 1] : sum[j]) + triangle[i][j];
            }
            sum[0] += triangle[i][0];
        }
        int result = sum[0];
        for (int i = 1; i < sum.size(); ++i)
            if (sum[i] < result)
                result = sum[i];
        return result;
    }
};
