class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();

        if (obstacleGrid[m - 1][n - 1] == 1) return 0;

        vector<vector<long>> counts(m, vector<long>(n, 0));
        counts[m - 1][n - 1] = 1;
        
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (obstacleGrid[r][c] == 1) continue;

                long rightCount = c + 1 < n ? counts[r][c + 1] : 0;
                long downCount = r + 1 < m ? counts[r + 1][c] : 0;
                counts[r][c] += rightCount + downCount; 
            }
        }

        return counts[0][0];
    }
};