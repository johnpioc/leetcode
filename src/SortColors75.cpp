class Solution {
public:
    void quickSort(int l, int r, vector<int>& nums) {
        if (l >= r) return;

        int pivot = nums[r];
        int i = l;

        for (int j = l; j < r; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[r]);

        quickSort(l, i - 1, nums);
        quickSort(i + 1, r, nums);
    }
    void sortColors(vector<int>& nums) {
        quickSort(0, nums.size() - 1, nums);
    }
};