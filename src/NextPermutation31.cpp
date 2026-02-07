class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;

        int a = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            a = i;
            if (i < nums.size() - 1 && nums[i] < nums[i + 1]) break;
        }

        int b = a + 1;
        for (int i = a + 1; i < nums.size(); i++) {
            if (abs(nums[b] - nums[a]) >= abs(nums[i] - nums[a]) && nums[i] > nums[a]) b = i;
        }

        if (nums[a] < nums[b]) {
            swap(nums[a], nums[b]);
            reverse(nums.begin() + a + 1, nums.end());
        } else {
            reverse(nums.begin(), nums.end());
        }

    }
};