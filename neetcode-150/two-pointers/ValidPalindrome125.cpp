#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int startIndex = 0;
        int endIndex = s.size() - 1;

        while (startIndex < endIndex) {
            // 1. Make both letters lowercase and check if they belong to the alphabet
            char startChar = static_cast<char>(tolower(s[startIndex]));
            char endChar = static_cast<char>(tolower(s[endIndex]));

            if (!isalnum(startChar)) {
                startIndex++;
                continue;
            }

            if (!isalnum(endChar)) {
                endIndex--;
                continue;
            }

            // 2. Check that both characters are equal
            if (startChar == endChar) {
                startIndex++;
                endIndex--;
            } else {
                return false;
            }
        }

        return true;
    }
};