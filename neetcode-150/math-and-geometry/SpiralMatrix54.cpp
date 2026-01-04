class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> path;
        travel(0, 0, 0, 1, matrix, path);
        return path;
    }

    void travel(int row, int col, int deltaRow, int deltaCol, vector<vector<int>>& matrix, vector<int>& path) {
        if (row == matrix.size() || row == -1) return;
        if (col == matrix.front().size() || col == -1) return;

        path.push_back(matrix[row][col]);
        matrix[row][col] = 101;

        if (deltaRow > 0 && (row + deltaRow == matrix.size() || matrix[row + deltaRow][col] == 101)) {
            if (col - 1 == -1 || matrix[row][col - 1] == 101) return;
            deltaRow = 0;
            deltaCol = -1;
        }

        else if (deltaRow < 0 && (row + deltaRow == -1 || matrix[row + deltaRow][col] == 101)) {
            if (col + 1 == matrix.front().size() || matrix[row][col + 1] == 101) return;
            deltaRow = 0;
            deltaCol = 1;
        }

        else if (deltaCol > 0 && (col + deltaCol == matrix.front().size() || 
            matrix[row][col + deltaCol] == 101)) {
            if (row + 1 == matrix.size() || matrix[row + 1][col] == 101) return;
            deltaRow = 1;
            deltaCol = 0;
        }

        else if (deltaCol < 0 && (col + deltaCol == -1 || matrix[row][col + deltaCol] == 101)) {
            if (row - 1 == - 1 || matrix[row - 1][col] == 101) return;
            deltaRow = -1;
            deltaCol = 0;
        }

        travel(row + deltaRow, col + deltaCol, deltaRow, deltaCol, matrix, path);
    }
};