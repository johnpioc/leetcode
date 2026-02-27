class Solution {
public:


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> increasing;

        for (int i = 0; i < n; i++) {
            while (!increasing.empty() && heights[increasing.top()] >= heights[i]) increasing.pop();
            if (!increasing.empty()) pse[i] = increasing.top();
            increasing.push(i);
        }

        increasing = stack<int>();

        for (int i = n - 1; i >= 0; i--) {
            while (!increasing.empty() && heights[increasing.top()] >= heights[i]) increasing.pop();
            if (!increasing.empty()) nse[i] = increasing.top();
            increasing.push(i);
        }

        int maxRec = 0;
        for (int i = 0; i < n; i++) {
            maxRec = max(maxRec, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxRec;
    }
};