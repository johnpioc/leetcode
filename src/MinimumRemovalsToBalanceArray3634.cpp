class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if (nums.size() == 1) return 0;

        sort(nums.begin(), nums.end());
        int l = nums.size() - 2, r = nums.size() - 1;

        int output = nums.size() - 1;
        while (l >= 0 && r > 0) {
            if ((long long)nums[l] * k >= nums[r]) {
                output = output < l + nums.size() - r - 1 ? output : l + nums.size() - r - 1;
                l--;
            } else {
                r--;
                if (l == r) l--;
            }
        }

        return output;
    }
};