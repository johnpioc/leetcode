class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int steps = 0;

        while (l < n - 1 && r < n - 1) {
            steps++;

            int newR = r;
            for (int i = l; i <= r && i < n; i++) {
                newR = max(newR, i + nums[i]);
            }

            l = r + 1;
            r = newR;
        }

        return steps;
    }
};