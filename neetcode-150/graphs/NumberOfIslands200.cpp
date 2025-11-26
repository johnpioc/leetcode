class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 1. Create an adjacency list out of the grid
        unordered_map<string, vector<string>> adj;

        int m = grid.size();
        int n = grid[0].size();

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[y][x] == '1') {
                    string key = to_string(y) + "," + to_string(x);
                    adj[key] = vector<string>();

                    // 1a. Check top, bottom, left and right for connections
                    if (y > 0 && grid[y-1][x] == '1') adj[key].push_back(to_string(y-1) + "," + to_string(x));
                    if (y < m - 1 && grid[y+1][x] == '1') adj[key].push_back(to_string(y+1) + "," + to_string(x));
                    if (x > 0 && grid[y][x-1] == '1') adj[key].push_back(to_string(y) + "," + to_string(x-1));
                    if (x < n - 1 && grid[y][x+1] == '1') adj[key].push_back(to_string(y) + "," + to_string(x+1));
                }
            }
        }

        // 2. Perform search on each key and keep track of which one's we've already seen. Count the number of unseen
        set<string> seen;
        stack<string> toSee;

        int numOfComponents = 0;
        for (const auto& [key, neighbours] : adj) {
            if (!seen.contains(key)) {
                toSee.push(key);
                seen.insert(key);
                numOfComponents++;

                while (toSee.size() > 0) {
                    string current = toSee.top();
                    toSee.pop();

                    for (string neighbour : adj[current]) {
                        if (!seen.contains(neighbour)) {
                            seen.insert(neighbour);
                            toSee.push(neighbour);
                        }
                    }
                }

            }
        }

        return numOfComponents;;
    }
};