class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        int x = n - 1, y = 0;
        while ((x != 0 || y != m - 1) && matrix[y][x] != target) {
            if (matrix[y][x] > target) {
                if (x == 0) break;
                else x--;
            } else if (matrix[y][x] < target) {
                if (y == m - 1) break;
                else y++; 
            }
        }

        return matrix[y][x] == target;
    }
};
