class Solution {
public:

    int maxArea(vector<int>& height) {
        int largestArea = INT_MIN;
        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            int lowerHeight = min(height[l], height[r]);
            int distance = r - l;
            int area = lowerHeight * distance;

            if (area > largestArea) {
                largestArea = area;
            }

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return largestArea;
    }
};