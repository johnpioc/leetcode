class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        vector<bool> codes(pow(2, k), false);
        string_view view(s);

        for (int i = 0; i < s.size() - k + 1; i++) {
            string_view current = view.substr(i, k);
            int currentNum = 0;
            for (int j = 0; j < k; j++) { 
                currentNum += current[j] == '1' ? pow(2, k - j - 1) : 0;
            }
            codes[currentNum] = true;
        }

        return find(codes.begin(), codes.end(), false) == codes.end();
    }
};