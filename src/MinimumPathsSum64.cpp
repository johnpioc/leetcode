class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (r == m - 1 && c == n - 1) continue;

                int rightCost = c + 1 < n ? grid[r][c + 1] : INT_MAX;
                int downCost = r + 1 < m ? grid[r + 1][c] : INT_MAX;

                grid[r][c] = min(
                    rightCost == INT_MAX ? rightCost : grid[r][c] + rightCost, 
                    downCost == INT_MAX ? downCost : grid[r][c] + downCost
                );
            }
        }

        return grid[0][0];
    }
};