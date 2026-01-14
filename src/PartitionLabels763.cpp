class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurence;

        for (int i = 0; i < s.size(); i++) {
            lastOccurence[s[i]] = i;
        }

        vector<int> output;
        int currentMaxIndex = 0;
        int lastMaxIndex = -1;
        for (int i = 0; i < s.size(); i++) {
            currentMaxIndex = max(currentMaxIndex, lastOccurence[s[i]]);
            if (i == currentMaxIndex) {
                output.push_back(currentMaxIndex - lastMaxIndex);
                currentMaxIndex = i;
                lastMaxIndex = i;
            }
        }

        return output;
    }
};