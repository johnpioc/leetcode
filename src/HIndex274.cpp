class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](const int a, const int b) { 
            return a > b;
        });

        int i;
        for (i = 0; i < citations.size(); i++) {
            if (citations[i] < i + 1) break;
        }

        return i;
    }
};
