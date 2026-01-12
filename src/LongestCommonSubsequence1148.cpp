class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    cache[i][j] = 1 + cache[i + 1][j + 1];
                } else {
                    cache[i][j] = max(cache[i][j + 1], cache[i + 1][j]);
                }
            }
        }

        return cache[0][0];
    }
};