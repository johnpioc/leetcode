class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int end = intervals[0][1];
        int output = 0;

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& interval = intervals[i];
            if (end > interval[0]) {
                output++;
            } else {
                end = interval[1];
            }
        }

        return output;
    }
};