class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [](const vector<int>& a, const vector<int>& b) {
            double distA = sqrt(pow(0 - a[0],2.0) + pow(0 - a[1], 2.0));
            double distB = sqrt(pow(0 - b[0],2.0) + pow(0 - b[1], 2.0));

            return distA > distB;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> pq(comparator);
        for (vector<int>& point : points) {
            pq.push(point);
        }

        vector<vector<int>> output;
        for (int i = 0; i < k; i++) {
            output.push_back(pq.top());
            pq.pop();
        }

        return output;
    }
};