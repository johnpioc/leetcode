class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void dfs(int row, int col, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[row][col] = true;
        for (vector<int> direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];

            if (newRow >= 0 && newRow < heights.size() && newCol >= 0 && newCol < heights.front().size()
                && !ocean[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                    dfs(newRow, newCol, ocean, heights);
                }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights.front().size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            dfs(i, 0, pacific, heights);
            dfs(i, m - 1, atlantic, heights);
        }

        for (int i = 0; i < m; i++) {
            dfs(0, i, pacific, heights);
            dfs(n - 1, i, atlantic, heights);
        }

        vector<vector<int>> output;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (pacific[row][col] && atlantic[row][col])
                    output.push_back({ row, col });
            }
        }

        return output;
    }
};