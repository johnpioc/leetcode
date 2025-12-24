class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> cache(nums.size(), vector<int>(2001, -1));
        return build(0, 0, target, nums, cache);
    }

    int build(int index, int current, int target, vector<int>& nums, vector<vector<int>>& cache) {
        if (index == nums.size()) {
            return current == target;
        }

        if (cache[index][current + 1000] != -1) return cache[index][current + 1000];        

        return cache[index][current + 1000] = build(index + 1, current - nums[index], target, nums, cache) 
            + build(index + 1, current + nums[index], target, nums, cache);
    }
};