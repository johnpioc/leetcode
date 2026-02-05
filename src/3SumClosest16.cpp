class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int output = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            twoSum(nums[i], i + 1, nums, target, output);
        }

        return output;
    }

    void twoSum(int currentSum, int start, vector<int>& nums, int target, int& output) {
        if (start >= nums.size() - 1) return;
        int l = start, r = nums.size() - 1;

        while (l < r) {
            int sum = currentSum + nums[l] + nums[r];
            if (abs(target - sum) < abs(target - output)) output = sum;

            if (sum > target) r--;
            else if (sum < target) l++;
            else {
                r--;
                l++;
            }
        }
    }
};