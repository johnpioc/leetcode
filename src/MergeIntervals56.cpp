class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else return a[0] < b[0];
        });

        vector<vector<int>> output;
        bool constructing = false;
        vector<int> newInterval;

        for (vector<int>& interval : intervals) {
            if (constructing) {
                if (newInterval[1] < interval[0]) {
                    output.push_back(newInterval);
                    constructing = false;
                }

                newInterval[1] = max(newInterval[1], interval[1]);
            }

            if (!constructing) {
                constructing = true;
                newInterval = interval;
            }
            
        }

        if (constructing) output.push_back(newInterval);

        return output;
    }
};