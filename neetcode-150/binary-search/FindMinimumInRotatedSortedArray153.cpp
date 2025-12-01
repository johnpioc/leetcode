class Solution {
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return nums[l];
        }

        int mid = (l + r) / 2;
        int current = nums[mid];

        cout << "Current: " << current << "\n";

        int left = nums[l];

        if (current >= left) {
            return min(left, binarySearch(nums, mid + 1, r));
        } else {
            return min(current, binarySearch(nums, l, mid - 1));
        }
    }
};