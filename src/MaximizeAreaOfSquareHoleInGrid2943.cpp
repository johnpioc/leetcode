class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int longestRunH = 1;
        int newLongestRunH = 1;
        int longestRunV = 1;
        int newLongestRunV = 1;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] == 1) {
                newLongestRunH++;
            } else {
                longestRunH = max(longestRunH, newLongestRunH);
                newLongestRunH = 1;
            }
        }

        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] == 1) {
                newLongestRunV++;
            } else {
                longestRunV = max(longestRunV, newLongestRunV);
                newLongestRunV = 1;
            }
        }

        longestRunV = max(longestRunV, newLongestRunV);
        longestRunH = max(longestRunH, newLongestRunH);

        int longestRun = min(longestRunV + 1, longestRunH + 1);

        return (int) pow(longestRun, 2);
    }
};