#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

using std::vector;
using std::max;
using std::priority_queue;
using std::stack;
using std::pair;
using std::make_pair;

class BestTimeToBuyAndSellStockIV {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (k > prices.size() / 2) {
            int result = 0;
            for (int i = 1; i < prices.size(); ++i)
                result += max(0, prices[i] - prices[i - 1]);
            return result;
        }
        /*
        if (prices.empty())
            return 0;
        vector<int> profits(prices.size());
        for (int i = 0; i < k; ++i) {
            int buy = profits[0] - prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                int tmp = max(buy, profits[j] - prices[j]);
                profits[j] = max(profits[j - 1], prices[j] + buy);
                buy = tmp;
            }
        }
        return profits[prices.size() - 1];
        */

        /*
        if (prices.empty())
            return 0;
        vector<int> buy(k + 1, -prices[0]), sell(k + 1);
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            }
        }
        return sell[k];
        */

        priority_queue<int> profits;
        stack<pair<int, int>> vp_pairs;
        int n = prices.size(), p = 0, v = 0;
        while (p < n) {
            for (v = p; v < n - 1 && prices[v] >= prices[v + 1]; ++v);
            for (p = v + 1; p < n && prices[p] >= prices[p - 1]; ++p);

            while (!vp_pairs.empty() && prices[vp_pairs.top().first] >= prices[v]) {
                profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
                vp_pairs.pop();
            }

            while (!vp_pairs.empty() && prices[vp_pairs.top().second - 1] <= prices[p - 1]) {
                profits.push(prices[vp_pairs.top().second - 1] - prices[v]);
                v = vp_pairs.top().first;
                vp_pairs.pop();
            }
            vp_pairs.push(make_pair(v, p));
        }

        while (!vp_pairs.empty()) {
            profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }

        int result = 0;
        for (int i = 0; i < k && !profits.empty(); ++i) {
            result += profits.top();
            profits.pop();
        }
        return result;
    }
};
