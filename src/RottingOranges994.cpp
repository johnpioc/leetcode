class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int numOfFresh = 0;
        queue<array<int,2>> toSearch;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) numOfFresh++;
                else if (grid[row][col] == 2) {
                    toSearch.push({ row, col });
                }
            }
        }

        int time = 0;
        while (numOfFresh > 0 && !toSearch.empty()) {
            int currentLength = toSearch.size();

            for (int i = 0; i < currentLength; i++) {
                array<int,2> currentPosition = toSearch.front();
                toSearch.pop();

                int x = currentPosition[1];
                int y = currentPosition[0];

                // Check top
                if (y > 0 && grid[y - 1][x] == 1) {
                    numOfFresh--;
                    toSearch.push({ y - 1, x });
                    grid[y - 1][x] = 2;
                }

                // Check right
                if (x + 1 < m && grid[y][x + 1] == 1) {
                    numOfFresh--;
                    toSearch.push({ y, x + 1 });
                    grid[y][x + 1] = 2;
                }

                // Check bottom
                if (y + 1 < n && grid[y + 1][x] == 1) {
                    numOfFresh--;
                    toSearch.push({ y + 1, x });
                    grid[y + 1][x] = 2;
                }

                // Check left
                if (x > 0 && grid[y][x - 1] == 1) {
                    numOfFresh--;
                    toSearch.push({ y, x - 1 });
                    grid[y][x-1] = 2;
                }
            }

            time++;
        }

        if (numOfFresh > 0) return -1;
        else return time;
    }
}; 