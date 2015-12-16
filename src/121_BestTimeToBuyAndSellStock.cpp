#include <vector>

using std::vector;

class BestTimeToBuyAndSellStock {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        int result = 0;
        int buyPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] <= buyPrice)
                buyPrice = prices[i];
            else if (result < prices[i] - buyPrice)
                result = prices[i] - buyPrice;
        }
        return result;
    }
};
