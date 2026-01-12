class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int longestLength = 0;

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > longestLength) {
                    res = s.substr(l, r - l + 1);
                    longestLength = r - l + 1;
                }
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > longestLength) {
                    res = s.substr(l, r - l + 1);
                    longestLength = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return res;
    }
};