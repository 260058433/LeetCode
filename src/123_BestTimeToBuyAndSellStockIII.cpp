#include <vector>

using std::vector;

class BestTimeToBuyAndSellStockIII {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        int first = 0, second = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] <= buy) {
                buy = prices[i];
            } else {
            }
        }          
        return result;
    }
};
