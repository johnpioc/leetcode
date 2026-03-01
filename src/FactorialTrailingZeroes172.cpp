class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;

        for (int divisor = 5; divisor <= n; divisor *= 5) {
            int curr = divisor;
            while (curr <= n) {
                res++;
                curr += divisor;
            }
        }

        return res;
    }
};