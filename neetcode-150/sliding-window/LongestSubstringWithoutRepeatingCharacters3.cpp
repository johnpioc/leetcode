class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) return s.length();

        int leftIndex = 0;
        int rightIndex = 0;

        set<char> rollingSet;

        rollingSet.insert(s[leftIndex]);

        int longestLength = 1;
        while (rightIndex != s.size() - 1) {
            rightIndex++;

            while (rollingSet.contains(s[rightIndex]) && leftIndex < rightIndex) {
                rollingSet.erase(s[leftIndex]);
                leftIndex++;
            }

            rollingSet.insert(s[rightIndex]);

            int currentLength = rightIndex - leftIndex + 1;
            if (currentLength > longestLength) longestLength = currentLength;
        }

        return longestLength;
    }
};