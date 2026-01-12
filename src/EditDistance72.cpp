class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> cache(word1.size(), vector<int>(word2.size(), -1));
        return build(0, 0, word1, word2, cache);
    }

    int build(int index1, int index2, string& word1, string& word2, vector<vector<int>>& cache) {
        if (index2 >= word2.size()) return word1.size() - index1;
        if (index1 >= word1.size()) return word2.size() - index2;
        if (cache[index1][index2] != -1) return cache[index1][index2];

        // Same character
        if (word1[index1] == word2[index2]) {
            cache[index1][index2] = build(index1 + 1, index2 + 1, word1, word2, cache);
        } else {
            cache[index1][index2] = min({
                1 + build(index1, index2 + 1, word1, word2, cache), // Insert
                1 + build(index1 + 1, index2, word1, word2, cache), // Delete
                1 + build(index1 + 1, index2 + 1, word1, word2, cache)// Replace
            });
        }

        return cache[index1][index2];
    }
};