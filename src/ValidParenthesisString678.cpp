class Solution {
public:
    bool checkValidString(string s) {
        stack<int> free;
        stack<int> toMatch;

        for (int i = 0; i < s.size(); i++) {
            char character = s[i];
            if (character == '(') {
                toMatch.push(i);
            } else if (character == '*') {
                free.push(i);
            } else {
                if (toMatch.empty()) {
                    if (free.size() > 0) free.pop();
                    else return false;
                } else {
                    toMatch.pop();
                }
            }
        }
        while (toMatch.size() && free.size() && toMatch.top() < free.top()) {
            toMatch.pop();
            free.pop();
        }

        return toMatch.empty();
    }
};