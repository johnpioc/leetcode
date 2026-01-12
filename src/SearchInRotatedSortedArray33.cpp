class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {
        if (l > r) {
            return -1;
        }

        int mid = (l + r) / 2;
        int current = nums[mid];

        int left = nums[l];
        int right = nums[r];

        if (target < current) {
            if (current >= left) {
                if (target >= left) {
                    return binarySearch(nums, l, mid - 1, target);
                } else {
                    return binarySearch(nums, mid + 1, r, target);
                }
            } else {
                if (target >= left) {
                    return binarySearch(nums, mid + 1, r, target);
                } else {
                    return binarySearch(nums, l, mid - 1, target);
                }
            }
        } else if (target > current) {
            if (current >= left) {
                return binarySearch(nums, mid + 1, r, target);
            } else {
                if (target > right) {
                    return binarySearch(nums, l, mid - 1, target);
                } else {
                    return binarySearch(nums, mid + 1, r, target);
                }
            }
        }

        return mid;
    }
};