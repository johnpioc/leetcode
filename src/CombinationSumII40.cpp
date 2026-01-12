class Solution {
public:
    vector<vector<int>> res;

    void getTerms(int currentIndex, vector<int>& terms, int currentSum, vector<int>& candidates, int target)
    {
        if (currentSum == target) {
            res.push_back(terms);
            return;
        }

        if (currentSum > target || currentIndex >= candidates.size()) return;

        terms.push_back(candidates[currentIndex]);
        getTerms(currentIndex + 1, terms, currentSum + candidates[currentIndex], candidates, target);

        terms.pop_back();

        while (currentIndex + 1 < candidates.size() 
            && candidates[currentIndex] == candidates[currentIndex + 1]) {
            currentIndex++;
        }

        getTerms(currentIndex + 1, terms, currentSum, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> terms;

        getTerms(0, terms, 0, candidates, target);
        return res;
    }
};