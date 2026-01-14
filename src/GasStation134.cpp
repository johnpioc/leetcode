class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int total = 0;
        int startingIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];

            if (total < 0) {
                total = 0;
                startingIndex = i + 1;
            }
        }

        return startingIndex;
    }
};