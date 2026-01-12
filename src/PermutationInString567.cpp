class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();

        if (s1Size > s2Size) return false;

        unordered_map<char, int> s1Counts;
        unordered_map<char, int> s2Counts;

        for (int i = 0; i < s1Size; i++) {
            char currentS1Char = s1[i];

            if (s1Counts.contains(currentS1Char)) {
                s1Counts[currentS1Char]++;
            } else {
                s1Counts[currentS1Char] = 1;
            }

            char currentS2Char = s2[i];

            if (s2Counts.contains(currentS2Char)) {
                s2Counts[currentS2Char]++;
            } else {
                s2Counts[currentS2Char] = 1;
            }
        }

        int leftIndex = 0;
        bool output = false;
        while (leftIndex + s1Size <= s2Size) {
            bool matches = true;
            for (auto [key, value]: s1Counts) {
                if (value != s2Counts[key]) {
                    matches = false;
                    break;
                }
            }

            if (matches) {
                output = true;
                break;
            }

            leftIndex++;
            s2Counts[s2[leftIndex - 1]]--;
            s2Counts[s2[leftIndex + s1Size - 1]]++;
        }

        return output;
    }
};