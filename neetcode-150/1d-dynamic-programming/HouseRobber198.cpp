class Solution {
public:
    int calcMaxMoney(int i, vector<int>& nums, vector<int>* maxMoney) {
        if (i >= nums.size()) {
            return 0;
        }

        if ((*maxMoney)[i] != -1) {
            return (*maxMoney)[i];
        }

        return ((*maxMoney)[i] = max(nums[i] + calcMaxMoney(i + 2, nums, maxMoney), 
            nums[i] + calcMaxMoney(i + 3, nums, maxMoney)));
    }

    int rob(vector<int>& nums) {
        vector<int> maxMoney(nums.size(), -1);
        return max(calcMaxMoney(0, nums, &maxMoney), calcMaxMoney(1, nums, &maxMoney));
    }
};