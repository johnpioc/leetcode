class Solution {
public:
    vector<int> fibCache;

    int fib(int n) {
        if (n <= 1) {
            return 1;
        }

        if (fibCache[n] != 0) {
            return fibCache[n];
        }

        return (fibCache[n] = fib(n - 1) + fib(n - 2));
    }

    int climbStairs(int n) {
        fibCache.resize(n + 1, 0);
        int numOfWays = fib(n);

        return numOfWays;
    }
};