class Solution {
public:
    unordered_map<int, bool> cache;
    bool wordBreak(string s, vector<string>& wordDict) {
        return canSegment(0, 1, s, wordDict);
    }

    bool canSegment(int currentIndex, int currentLen, string& s, vector<string>& wordDict) {
        if (currentIndex + currentLen > s.size()) return false;
        if (cache.contains(currentIndex)) return cache[currentIndex];

        string substring = s.substr(currentIndex, currentLen);
        bool res = false;

        for (string word : wordDict) {
            if (word == substring) {
                res = true;
                break;
            }
        }

        if (currentIndex + currentLen == s.size()) {
            return cache[currentIndex] = res;
        }

        if (res) {
            return cache[currentIndex] = canSegment(currentIndex + currentLen, 1, s, wordDict) ||
                canSegment(currentIndex, currentLen + 1, s, wordDict);
        } else {
            return cache[currentIndex] = canSegment(currentIndex, currentLen + 1, s, wordDict);
        }
    }
};