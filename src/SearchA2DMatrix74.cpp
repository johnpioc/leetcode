class Solution {
public:
    vector<int> getTrueIndex(int rawIndex, int m) {
        return { rawIndex % m, rawIndex / m };
    }

    bool binarySearch(vector<vector<int>>& matrix, int target, int leftIndex, int rightIndex, int m) {
        if (leftIndex >= rightIndex - 1) {
            vector<int> leftTrueIndex = getTrueIndex(leftIndex, m);

            if (matrix[leftTrueIndex[1]][leftTrueIndex[0]] == target) return true;
            
            vector<int> rightTrueIndex = getTrueIndex(rightIndex, m);

            if (matrix[rightTrueIndex[1]][rightTrueIndex[0]] == target) return true;

            return false;
        }

        int rawIndex = (leftIndex + rightIndex) / 2;
        vector<int> trueIndex = getTrueIndex(rawIndex, m);
        int x = trueIndex[0];
        int y = trueIndex[1];

        if (matrix[y][x] == target) return true;
        else if (matrix[y][x] > target) return binarySearch(matrix, target, leftIndex, rawIndex, m);
        else return binarySearch(matrix, target, rawIndex, rightIndex, m);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int numOfNums = n * m;
        int leftIndex = 0;
        int rightIndex = numOfNums - 1;

        return binarySearch(matrix, target, leftIndex, rightIndex, m);
    }
};