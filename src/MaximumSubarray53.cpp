class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> maxSums(nums.size(), INT_MIN);
        maxSums[0] = nums[0];
        int globalMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxSums[i] = max(maxSums[i - 1] + nums[i], nums[i]);
            globalMax = max(globalMax, maxSums[i]);
        }

        return globalMax;
    }
};