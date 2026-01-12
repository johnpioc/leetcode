class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProducts(nums.size());
        vector<int> suffixProducts(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefixProducts[i] = nums[i];
                suffixProducts[nums.size() - i - 1] = nums[nums.size() - i - 1];
            } else {
                prefixProducts[i] = nums[i] * prefixProducts[i - 1];
                suffixProducts[nums.size() - i - 1] = nums[nums.size() - i - 1] *     
                    suffixProducts[nums.size() - i];
            }
        }

        vector<int> output(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                output[i] = suffixProducts[i + 1];
            } else if (i == nums.size() - 1) {
                output[i] = prefixProducts[i - 1];
            } else {
                output[i] = prefixProducts[i - 1] * suffixProducts[i + 1];
            }
        }

        return output;
    }
};