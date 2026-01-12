class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> cache;
        return getDecodings(s, 0, cache);
    }

    int getDecodings(string s, int index, unordered_map<int, int>& cache) {
        if (index == s.size()) return 1;
        if (s[index] == '0') return 0;
        if (cache.contains(index)) return cache[index];

        int numOfWays = getDecodings(s, index + 1, cache);
        if (index < s.size() - 1) {
            if (s[index] == '1' || (s[index] == '2' && (s[index + 1] - '0') < 7)) {
                numOfWays += getDecodings(s, index + 2, cache);
            }
        }

        return cache[index] = numOfWays;
    }
};