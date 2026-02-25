class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int current = triangle[i][j];
                int left = i + 1 < triangle.size() ? triangle[i + 1][j] : 0;
                int right = i + 1 < triangle.size() ? triangle[i + 1][j + 1] : 0;
                triangle[i][j] = min(current + left, current + right);
            }
        }

        return triangle[0][0];
    }
};