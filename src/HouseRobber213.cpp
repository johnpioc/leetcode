class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums.front();
        return max(getMoney(nums, 1, nums.size() - 1), getMoney(nums, 0, nums.size() - 2));
    }

    int getMoney(vector<int>& nums, int startIndex, int maxIndex) {
        int rob1 = 0;
        int rob2 = 0;

        for (int i = startIndex; i <= maxIndex; i++) {
            int num = nums[i];
            int newRob = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = newRob;
        }

        return rob2;
    }
};