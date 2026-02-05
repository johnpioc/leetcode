class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> array = { nums[i] };
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            threeSum(nums[i], i + 1, array, nums, target, result);
        }
        return result;
    }

    void threeSum(long long currentSum, int start, vector<int>& array, vector<int>& nums, 
        int target, vector<vector<int>>& result) {
        if (start >= nums.size() - 2) return;

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            array.push_back(nums[i]);
            twoSum(currentSum + nums[i], i + 1, array, nums, target, result);
            array.pop_back();
        }
    }

    void twoSum(long long currentSum, int start, vector<int>& array, vector<int>& nums, int target, 
        vector<vector<int>>& result) {
        if (start >= nums.size() - 1) return;

        int l = start, r = nums.size() - 1;

        while (l < r) {
            long long sum = currentSum + nums[l] + nums[r];
            if (sum > target) r--;
            else if (sum < target) l++; 
            else {
                result.push_back({ array[0], array[1], nums[l++], nums[r--] });
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
        }
    }
};