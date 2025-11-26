#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> toMatch;

        for (char currentChar : s) {
            if (
                currentChar == '[' ||
                currentChar == '{' ||
                currentChar == '('
            ) {
                toMatch.push(currentChar);
            } else {
                if (toMatch.size() > 0) {
                    char matchingBracket = toMatch.top();
                    toMatch.pop();

                    if (matchingBracket == '[' && currentChar != ']') return false;
                    if (matchingBracket == '(' && currentChar != ')') return false;
                    if (matchingBracket == '{' && currentChar != '}') return false;
                } else {
                    return false;
                }

            }
        }

        if (toMatch.size() > 0) {
            return false;
        }

        return true;
    }
};