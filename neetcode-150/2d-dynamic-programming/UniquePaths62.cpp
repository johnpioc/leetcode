class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return build(m - 1, n - 1, m, n, cache);
    }

    int build(int row, int col, int m, int n, vector<vector<int>>& cache) {
        if (row == 0 && col == 0) return 1;
        if (row < 0 || row >= m || col < 0 || col >= n) return 0;
        if (cache[row][col] != -1) return cache[row][col];

        return cache[row][col] = build(row - 1, col, m, n, cache) + build(row, col - 1, m, n, cache);
    }
};