#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> output(2);

        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int complement = target - currentNumber;

            if (seen.contains(complement)) {
                output[0] = i;
                output[1] = seen[complement];
                break;
            } else {
                seen[currentNumber] = i;
            }
        }

        return output;
    }
};