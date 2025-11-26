class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size(), 0);

        for (int i = cost.size() - 1; i >= 0; i--) {
            int pathCost = cost[i];

            int oneStepCost = 0;
            int twoStepCost = 0;

            if (i < cost.size() - 1) {
                oneStepCost = minCost[i + 1];
            }

            if (i < cost.size() - 2) {
                twoStepCost = minCost[i + 2];
            }

            minCost[i] = pathCost + min(oneStepCost, twoStepCost);
        }

        return min(minCost[0], minCost[1]);
    }
};