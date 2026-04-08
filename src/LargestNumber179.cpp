class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for (int num : nums) numStrings.push_back(to_string(num));
        sort(numStrings.begin(), numStrings.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        string output = "";
        for (string numString : numStrings) output += numString;
        return output[0] == '0' ? "0" : output;
    }
};
