class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            int currentNum = i;

            while (currentNum > 0) {
                if (currentNum % 2 == 1) output[i]++;

                currentNum /= 2;
            }
        }

        return output;
    }
};