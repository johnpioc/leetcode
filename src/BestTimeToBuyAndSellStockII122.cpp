class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;

        int l = 0;

        while (l < prices.size()) {
            int r = l;
            while (r + 1 < prices.size() && prices[r] < prices[r + 1]) r++;
            prof += prices[r] - prices[l];
            l = r + 1;
        }

        return prof;
    }
};