class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (int num: nums) {
            if (counts.contains(num)) {
                counts[num]++;
            } else {
                counts[num] = 1;
            }
        }

        vector<array<int, 2>> mostFrequent;

        for (auto pair: counts) {
            mostFrequent.push_back({ pair.first, pair.second });
        }

        sort(mostFrequent.begin(), mostFrequent.end(), [](auto a, auto b) {
            return a[1] > b[1];
        });

        vector<int> output;

        for (int i = 0; i < k; i++) {
            output.push_back(mostFrequent[i][0]);
        }

        return output;
    }
};