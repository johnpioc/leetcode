class Solution {
public:
    vector<vector<int>> adj;
    vector<int> incoming;

    void dfs(int course, vector<int>& output) {
        output.push_back(course);
        incoming[course]--;

        for (int neighbour: adj[course]) {
            incoming[neighbour]--;
            if (incoming[neighbour] == 0) {
                dfs(neighbour, output);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        incoming = vector<int>(numCourses, 0);

        for (vector<int> prereq : prerequisites) {
            incoming[prereq[0]]++;
            adj[prereq[1]].push_back(prereq[0]);
        }

        vector<int> output;

        for (int i = 0; i < numCourses; i++) {
            if (incoming[i] == 0) {
                dfs(i, output);
            }
        }

        if (output.size() != numCourses) return {};
        return output;
    }
};