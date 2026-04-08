class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = prime[n] = false;

        for (int p = 2; p * p < n; p++) {
            if (prime[p]) {
                for (int i = p * p; i < n; i += p) {
                    prime[i] = false;
                }
            }
        }

        return count(prime.begin(), prime.end(), true);
    }
};
