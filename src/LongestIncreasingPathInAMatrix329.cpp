class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        vector<vector<int>> longestPaths(m, vector<int>(n, 1));

        int longest = 1;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                longest = max(longest, explore(r, c, matrix, longestPaths));
            }
        }

        return longest;
    }

    int explore(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& longestPaths) {
        if (longestPaths[r][c] != 1) return longestPaths[r][c];

        int m = matrix.size();
        int n = matrix.front().size();
        int res = 1;

        if (r - 1 >= 0 && matrix[r - 1][c] < matrix[r][c]) 
            res = max(res, 1 + explore(r - 1, c, matrix, longestPaths));
        if (r + 1 < m && matrix[r + 1][c] < matrix[r][c])
            res = max(res, 1 + explore(r + 1, c, matrix, longestPaths));
        if (c - 1 >= 0 && matrix[r][c - 1] < matrix[r][c])
            res = max(res, 1 + explore(r, c - 1, matrix, longestPaths));
        if (c + 1 < n && matrix[r][c + 1] < matrix[r][c])
            res = max(res, 1 + explore(r, c + 1, matrix, longestPaths));

        return longestPaths[r][c] = res;
    }
};