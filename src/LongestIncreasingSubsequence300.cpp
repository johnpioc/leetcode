class Solution {
public:
    unordered_map<int, int> cache;

    int getLength(int currentIndex, vector<int>& nums) {
        if (currentIndex == nums.size() - 1) return 1;

        if (cache.contains(currentIndex)) return cache[currentIndex];

        int maxLength = 1;
        for (int i = currentIndex + 1; i < nums.size(); i++) {
            if (nums[i] > nums[currentIndex])
                maxLength = max(maxLength, 1 + getLength(i, nums));
        }

        return maxLength;
    }

    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            cache[i] = getLength(i, nums);
            maxLength = max(cache[i], maxLength);
        }

        return maxLength;
    }
};