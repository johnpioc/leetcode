class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left, right = 0;
        int currentSum = nums[left];
        int result = currentSum >= target ? 1 : INT_MAX;

        while (right < nums.size() - 1) {
            right++;
            currentSum += nums[right];
            while (currentSum >= target && left <= right) {
                result = min(result, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};
