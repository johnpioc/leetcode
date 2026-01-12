class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        build({}, 0, 1, s, output);
        return output;
    }

    bool isPalindrome(int l, int r, string& s) {
        if (l >= r) return true;

        if (s[l] != s[r]) return false;

        return isPalindrome(l + 1, r - 1, s);
    }

    void build(vector<string> current, int startIndex, int length, string& s, vector<vector<string>>& output) {
        if (startIndex + length > s.size()) {
            return;
        }

        if (startIndex + length == s.size()) {
            if (isPalindrome(startIndex, startIndex + length - 1, s)) {
                current.push_back(s.substr(startIndex, length));
                output.push_back(current);
            }

            return;
        }
        
        if (length == 1) {
            current.push_back(s.substr(startIndex, 1));
            build(current, startIndex + 1, 1, s, output);
            current.pop_back();
            build(current, startIndex, 2, s, output);
        } else {
            if (isPalindrome(startIndex, startIndex + length - 1, s)) {
                current.push_back(s.substr(startIndex, length));
                build(current, startIndex + length, 1, s, output);
                current.pop_back();
                build(current, startIndex, length + 1, s, output);
            } else {
                build(current, startIndex, length + 1, s, output);
            }
        }

    }
};