class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        build({}, 0, candidates, target, res);
        return res;
    }

    void build(vector<int> terms, int currentSum, vector<int>& candidates, int target, vector<vector<int>>& res)
    {
        for (int i = 0; i < candidates.size(); i++) {
            if (terms.size() > 0 && candidates[i] > terms.back()) continue;
            
            if (currentSum + candidates[i] < target) {
                terms.push_back(candidates[i]);
                build(terms, currentSum + candidates[i], candidates, target, res);
                terms.pop_back();
            } else if (currentSum + candidates[i] == target) {
                terms.push_back(candidates[i]);
                res.push_back(terms);
                terms.pop_back();
            }
        }
    }
};