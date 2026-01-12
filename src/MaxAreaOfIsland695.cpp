class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Build adjacency list
        unordered_map<string, vector<string>> adj;

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (!grid[y][x]) continue;

                string currentPosition = to_string(x) + "," + to_string(y);
                adj[currentPosition] = {};

                // Check left
                if (x > 0 && grid[y][x - 1] == 1) {
                    adj[currentPosition].push_back(to_string(x - 1) + "," + to_string(y));
                }

                // Check Top
                if (y > 0 && grid[y - 1][x] == 1) {
                    adj[currentPosition].push_back(to_string(x) + "," + to_string(y - 1));
                }

                // Check Right
                if (x < grid[0].size() - 1 && grid[y][x + 1] == 1) {
                    adj[currentPosition].push_back(to_string(x + 1) + "," + to_string(y));
                }

                // Check Bottom
                if (y < grid.size() - 1 && grid[y + 1][x] == 1) {
                    adj[currentPosition].push_back(to_string(x) + "," + to_string(y + 1));
                }
            }
        }

        // Go through each connected component and count the number of nodes
        stack<string> toSearch;
        set<string> seen;
 
        int maxArea = 0;
        for (auto [currentPosition, _] : adj) {
            if (!seen.contains(currentPosition)) {
                toSearch.push(currentPosition);
                seen.insert(currentPosition);

                int currentArea = 0;
                cout << "New Component\n";
                while (toSearch.size() > 0) {
                    currentArea++;
                    string node = toSearch.top();
                    cout << "Node: " << node << "\n";
                    toSearch.pop();

                    for (string neighbour : adj[node]) {
                        if (!seen.contains(neighbour)) {
                            seen.insert(neighbour);
                            toSearch.push(neighbour);
                        }
                    }
                }

                if (currentArea > maxArea) {
                    maxArea = currentArea;
                }
            }
        }

        return maxArea;
    }
};