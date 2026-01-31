class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        bool constructing = false;
        bool integrated = false;

        for (int i = 0; i < intervals.size(); i++) {
            vector<int>& interval = intervals[i];

            if (!constructing && interval[0] <= newInterval[0] && newInterval[0] <= interval[1]) {
                constructing = true;
                newInterval[0] = min(interval[0], newInterval[0]);
            } else if (!constructing && !integrated && newInterval[0] < interval[0]) {
                constructing = true;
            }
            
            if (!constructing) output.push_back(interval);
            else {
                if (newInterval[1] < interval[0]) {
                    constructing = false;
                    integrated = true;
                    output.push_back(newInterval);
                    output.push_back(interval);
                }

                else if (interval[0] <= newInterval[1] && newInterval[1] <= interval[1]) {
                    constructing = false;
                    integrated = true;
                    newInterval[1] = max(interval[1], newInterval[1]);
                    output.push_back(newInterval);
                }
            }
        }

        if (!integrated) {
            output.push_back(newInterval);
        }

        return output;
    }
};