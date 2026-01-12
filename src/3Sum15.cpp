class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<int> firstNumberSeen;

        vector<vector<int>> output;
        for (int i = 0; i < nums.size() && nums[i] < 1; i++) {
            int currentNumber = nums[i];
            if (firstNumberSeen.contains(currentNumber)) continue;

            // Perform sorted two sum on the remaining elements
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = currentNumber + nums[l] + nums[r];

                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    output.push_back({ currentNumber, nums[l], nums[r] });
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
            }

            if (output.size() > 0 && output.back()[0] == currentNumber) {
                firstNumberSeen.insert(currentNumber);
            }
        }

        return output;
    }
};