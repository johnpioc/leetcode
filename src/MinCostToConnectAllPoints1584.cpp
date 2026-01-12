class Solution {
public:
    int getDistance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minKey(vector<int>& key, vector<bool>& mstSet) {
        int min = INT_MAX, minIndex;

        for (int i = 0; i < mstSet.size(); i++) {
            if (!mstSet[i] && key[i] < min)
                min = key[i], minIndex = i;
        }

        return minIndex;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parent(n);
        vector<int> key(n);
        vector<bool> mstSet(n);

        for (int i = 0; i < n; i++)
            key[i] = INT_MAX, mstSet[i] = false;

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < n - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < n; v++) {
                if (!mstSet[v] && getDistance(points[u], points[v]) < key[v])
                    parent[v] = u, key[v] = getDistance(points[u], points[v]);
            }
        }

        int output = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                output += getDistance(points[i], points[parent[i]]);
            }
        }

        return output;
    }
};