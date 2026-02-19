class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        char currentChar = s[0];
        int index = 0;
        int currentCount = 0;
        int currentNextCount = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == currentChar) {
                if (currentNextCount == 0) currentCount++;
                else {
                    res += min(currentCount, currentNextCount);
                    currentChar = s[i - 1];
                    currentCount = currentNextCount;
                    currentNextCount = 1;
                }
            }
            else currentNextCount++;
        }

        res += min(currentCount, currentNextCount);

        return res;
    }
};