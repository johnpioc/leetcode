class Solution {
public:
    int countSubstrings(string s) {
        int numOfPalindromes = s.size();

        for (int i = 0; i < s.size(); i++) {
            // Odd Case
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                numOfPalindromes++;
                l--;
                r++;
            }

            // Even case
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                numOfPalindromes++;
                l--;
                r++;
            }
        }
        return numOfPalindromes;
    }
};