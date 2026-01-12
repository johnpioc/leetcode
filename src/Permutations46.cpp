class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        
        for (int i = 0; i < nums.size(); i++) {
            vector<int> copy = nums;
            copy.erase(copy.begin() + i);
            build({ nums[i] }, copy, output);
        }

        return output;
    }

    void build(vector<int> current, vector<int> remaining, vector<vector<int>>& output) {
        if (remaining.empty()) {
            output.push_back(current);
            return;
        }

        for (int i = 0; i < remaining.size(); i++) {
            vector<int> copy = remaining;
            current.push_back(copy[i]);
            copy.erase(copy.begin() + i);
            build(current, copy, output);
            current.pop_back();
        }
    }
};