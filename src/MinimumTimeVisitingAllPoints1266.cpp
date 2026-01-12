class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            vector<int>& prev = points[i - 1];
            int x1 = prev[0] + 2000;
            int y1 = prev[1] + 2000;

            vector<int>& curr = points[i];
            int x2 = curr[0] + 2000;
            int y2 = curr[1] + 2000;

            int diagJumps = min(abs(x2 - x1), abs(y2 - y1));
            res += diagJumps + max(abs(x2 - x1) - diagJumps, abs(y2 - y1) - diagJumps);
        }

        return res;
    }
};