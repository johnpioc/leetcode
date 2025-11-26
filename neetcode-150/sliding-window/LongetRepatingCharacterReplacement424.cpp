class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int output = 1;
        int maxFrequency = 1;

        unordered_map<char, int> counts;
        counts[s[l]]++;

        for (int r = 1; r < s.size(); r++) {
            counts[s[r]]++;
            maxFrequency = max(maxFrequency, counts[s[r]]);

            while ((r - l + 1) - maxFrequency > k) {
                counts[s[l]]--;
                l++;
            }

            output = max(r - l + 1, output);
        }

        return output;
    }
};