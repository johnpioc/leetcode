class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> cache(2, vector<int>(prices.size() + 1, 0));

        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int buying = 1; buying >= 0; buying--) {
                if (buying) {
                    int buy = cache[0][i + 1] - prices[i];
                    int cooldown = cache[1][i + 1];
                    cache[buying][i] = max(buy, cooldown);
                } else {
                    int sell = (i + 2 < prices.size()) ? cache[1][i + 2] + prices[i] : prices[i];
                    int cooldown = cache[0][i + 1];
                    cache[buying][i] = max(sell, cooldown);
                }
            }
        }

        return cache[1][0];
    }
};