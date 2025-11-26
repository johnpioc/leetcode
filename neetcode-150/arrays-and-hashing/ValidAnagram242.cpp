#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> sWordCount;
        unordered_map<char, int> tWordCount;

        for (int i = 0; i < s.size(); i++) {
            if (sWordCount.contains(s[i])) {
                sWordCount[s[i]] += 1;
            } else {
                sWordCount[s[i]] = 1;
            }

            if (tWordCount.contains(t[i])) {
                tWordCount[t[i]] += 1;
            } else {
                tWordCount[t[i]] = 1;
            }
        }

        for (const auto& [key, value] : sWordCount) {
            if (tWordCount.contains(key)) {
                if (sWordCount[key] != tWordCount[key]) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};