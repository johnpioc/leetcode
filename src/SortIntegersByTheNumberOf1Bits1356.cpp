class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> counts(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            counts[i] = { popcount(static_cast<unsigned int>(arr[i])), arr[i] };
        }

        sort(counts.begin(), counts.end());

        vector<int> res(arr.size());
        for (int i = 0; i < res.size(); i++) { res[i] = counts[i].second; };
        return res;
    }
};