class Solution {
public:
    const unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i++) {
            if (primes.contains(popcount(static_cast<unsigned int>(i)))) res++;
        }

        return res;
    }
};