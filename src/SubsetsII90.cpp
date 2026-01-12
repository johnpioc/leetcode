class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        build(0, {}, nums, output);
        return output;
    }

    void build(int index, vector<int> current, vector<int>& nums, vector<vector<int>>& output) {
        if (index >= nums.size()) {
            output.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        build(index + 1, current, nums, output);
        current.pop_back();
        index++;
        while (index > 0 && index < nums.size() && nums[index] == nums[index - 1]) index++;

        build(index, current, nums, output);
    }
};