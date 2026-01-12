class Solution {
public:
    unordered_map<int, int> cache;

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = getCoins(coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }

    int getCoins(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (cache.contains(amount)) return cache[amount];

        int res = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                int result = getCoins(coins, amount - coin);
                if (result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }

        cache[amount] = res;
        return res;
    }
};