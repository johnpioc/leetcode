class Solution {
public:
    unordered_map<int, vector<char>> letterMap;

    vector<string> letterCombinations(string digits) {
        letterMap[2] = {'a', 'b', 'c'};
        letterMap[3] = {'d', 'e', 'f'};
        letterMap[4] = {'g', 'h', 'i'};
        letterMap[5] = {'j', 'k', 'l'};
        letterMap[6] = {'m', 'n', 'o'};
        letterMap[7] = {'p', 'q', 'r', 's'};
        letterMap[8] = {'t', 'u', 'v'};
        letterMap[9] = {'w', 'x', 'y', 'z'};

        vector<string> output;
        build("", 0, digits, output);
        return output;
    }

    void build(string current, int index, string& digits, vector<string>& output) {
        if (index >= digits.size()) {
            output.push_back(current);
            return;
        }

        for (char letter : letterMap[digits[index] - '0']) {
            current += letter;
            build(current, index + 1, digits, output);
            current.pop_back();
        }
    }
};