class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int maxNum = 1;
        int minNum = 1;

        for (int num : nums) {
            if (num == 0) {
                maxNum = 1;
                minNum = 1;
                continue;
            }

            int temp = maxNum * num;
            maxNum = max({ maxNum * num, num * minNum, num });
            minNum = min({ temp, num * minNum, num });

            res = max({ maxNum, res, minNum });
        }

        return res;
    }
};