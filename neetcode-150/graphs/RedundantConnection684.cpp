class Solution {
private:
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }

        return find(parent[i]);
    }

    void unite(int i, int j) {
        int irep = find(i);
        int jrep = find(j);
        parent[irep] = jrep;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<int> output = edges[0];
        for (vector<int> edge : edges) {
            if (find(edge[0] - 1) != find(edge[1] - 1)) {
                unite(edge[0] - 1, edge[1] - 1);
            } else {
                output = edge;
            }
        }

        return output;
    }
};