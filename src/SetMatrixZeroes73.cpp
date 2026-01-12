class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        unordered_set<int> rows;
        unordered_set<int> cols;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == 0) {
                    rows.insert(row);
                    cols.insert(col);
                }
            }
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (rows.contains(row) || cols.contains(col)) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};