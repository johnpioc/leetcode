class Solution {
public:

    void buildString(string currentString, int open, int close, vector<string>* output, int n) {
        if (open == close && open == n) {
            (*output).push_back(currentString);
            return;
        }

        if (open < n) {
            buildString(currentString + "(", open + 1, close, output, n);
        }

        if (close < open) {
            buildString(currentString + ")", open, close + 1, output, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> output;

        buildString("", 0, 0, &output, n);
        return output;
    }
};