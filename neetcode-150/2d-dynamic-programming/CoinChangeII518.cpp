class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> cache(coins.size(), vector<int>(amount + 1, -1));
        return build(0, 0, amount, coins, cache);
    }

    int build(int current, int index, int amount, vector<int>& coins, vector<vector<int>>& cache) {
        if (current >= amount || index == coins.size()) {
            return current == amount;
        }

        if (cache[index][current] != -1) return cache[index][current];

        return cache[index][current] = build(current + coins[index], index, amount, coins, cache) 
            + build(current, index + 1, amount, coins, cache);
    }
};