class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board[0].size();
        int n = board.size();

        queue<array<int,2>> toSearch;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
    
        // Go through all the outside cells and check which '0' cells are on the edge
        for (int x = 0; x < m; x++) {
            // Top line
            if (board[0][x] == 'O') {
                toSearch.push({ 0, x });
                visited[0][x] = true;
            }

            // Bottom line
            if (board[n - 1][x] == 'O') {
                toSearch.push({ n - 1, x });
                visited[n - 1][x] = true;
            }
        }

        for (int y = 0; y < n; y++) {
            // Left line
            if (board[y][0] == 'O') {
                toSearch.push({ y, 0 });
                visited[y][0] = true;
            }

            // Right line
            if (board[y][m - 1] == 'O') {
                toSearch.push({ y, m - 1 });
                visited[y][m - 1] = true;
            }
        }

        // BFS all connected 'O' cells and change them to 'X'
        while (toSearch.size() > 0) {
            array<int,2> currentPosition = toSearch.front();
            toSearch.pop();

            int x = currentPosition[1];
            int y = currentPosition[0];

            // Left
            if (x > 0 && board[y][x - 1] == 'O' && !visited[y][x-1]) {
                toSearch.push({ y, x - 1 });
                visited[y][x - 1] = true;
            }

            // Bottom
            if (y + 1 < n && board[y + 1][x] == 'O' && !visited[y + 1][x]) {
                toSearch.push({ y + 1, x });
                visited[y + 1][x] = true;
            }

            // Right
            if (x + 1 < m && board[y][x + 1] == 'O' && !visited[y][x + 1]) {
                toSearch.push({ y, x + 1 });
                visited[y][x + 1] = true;
            }

            // Top
            if (y > 0 && board[y - 1][x] == 'O' && !visited[y - 1][x]) {
                toSearch.push({ y - 1, x });
                visited[y - 1][x] = true;
            }
        }

        // Go through each cell and turn non-visited 'O' into 'X'
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (board[row][col] == 'O' && !visited[row][col]) {
                    board[row][col] = 'X';
                }
            }
        }
    }
};