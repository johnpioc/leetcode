class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = { - 1, -1 };

        int low = 0, high = nums.size() - 1;

        // First binary search the start index
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                result[0] = mid;
                high = mid - 1;
            }
        }

        if (result[0] == -1) return result;

        // Then binary search the second index
        low = result[0];
        high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                result[1] = mid;
                low = mid + 1;
            }
        }

        return result;
    }
};