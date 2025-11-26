#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> rightBiggest(prices.size());

        int biggest = -1;

        for (int i = prices.size() - 1; i >= 0; i--) {
            if (prices[i] >= biggest) {
                biggest = prices[i];
                rightBiggest[i] = -1;
            } else {
                rightBiggest[i] = biggest;
            }
        }

        int maximumProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            int currentPrice = prices[i];
            int highestPrice = rightBiggest[i];

            if (highestPrice == -1 || currentPrice >= highestPrice) {
                continue;
            } else {
                int profit = highestPrice - currentPrice;
                if (profit > maximumProfit) {
                    maximumProfit = profit;
                }
            }
        }

        return maximumProfit;
    }
};