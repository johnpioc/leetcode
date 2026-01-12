class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> blocks(9);

        bool output = true;

        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                char currentChar = board[y][x];

                if (currentChar != '.') {
                    // Check in row
                    if (rows[y].contains(currentChar)) {
                        output = false;
                        break;
                    } else {
                        rows[y].insert(currentChar);
                    }

                    // Check in columns
                    if (cols[x].contains(currentChar)) {
                        output = false;
                        break;
                    } else {
                        cols[x].insert(currentChar);
                    }

                    // Check in blocks
                    int blockNum = x / 3 + (y / 3) * 3;
                    if (blocks[blockNum].contains(currentChar)) {
                        output = false;
                        break;
                    } else {
                        blocks[blockNum].insert(currentChar);
                    }
                }
            }

            if (!output) break;
        }

        return output;
    }
};