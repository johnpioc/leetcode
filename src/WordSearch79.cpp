class Solution {
public:
    int m;
    int n;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board.front().size();

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (dfs(0, row, col, board, word)) return true;
            }
        }

        return false;
    }

    bool dfs(int index, int row, int col, vector<vector<char>>& board, string& word) {
        if (index >= word.size()) return true;

        if (row < 0 || row >= m) return false;
        if (col < 0 || col >= n) return false;
        if (word[index] != board[row][col]) return false;

        board[row][col] = '#';
        bool res = dfs(index + 1, row - 1, col, board, word) 
            || dfs(index + 1, row + 1, col, board, word)
            || dfs(index + 1, row, col - 1, board, word)
            || dfs(index + 1, row, col + 1, board, word);
        board[row][col] = word[index];

        return res;
    }
};