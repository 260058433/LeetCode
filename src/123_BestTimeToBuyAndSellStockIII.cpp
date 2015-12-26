#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class BestTimeToBuyAndSellStockIII {
public:
    int maxProfit(vector<int> &prices) {
        /*
        if (prices.empty())
            return 0;
        int n = prices.size();
        vector<int> dp(n);
        int k = 2;
        for (int i = 0; i < k; ++i) {
            int sum = dp[0] - prices[0];
            for (int j = 1; j < n; ++j) {
                if (sum < dp[j] - prices[j])
                    sum = dp[j] - prices[j];
                dp[j] = max(dp[j - 1], prices[j] + sum);
            }
        }
        return dp[n - 1];
        */

        if (prices.empty())
            return 0;
        int firstBuy = -prices[0], firstSell = 0, secondBuy = -prices[0], secondSell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            secondSell = max(secondSell, secondBuy + prices[i]);
            secondBuy = max(secondBuy, firstSell - prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            firstBuy = max(firstBuy, -prices[i]);
        }
        return secondSell;
    }
};
