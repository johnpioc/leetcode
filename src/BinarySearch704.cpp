#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int startIndex = 0;
        int endIndex = nums.size() - 1;
        int midIndex = (endIndex + startIndex) / 2;

        while (startIndex + 1 < endIndex) {
            int currentNumber = nums[midIndex];

            if (currentNumber == target) break;
            else if (currentNumber > target) {
                endIndex = midIndex;
            } else {
                startIndex = midIndex;
            }

            midIndex = (endIndex + startIndex) / 2;
        }

        if (nums[startIndex] == target) {
            return startIndex;
        } else if (nums[endIndex] == target) {
            return endIndex;
        }  else if (nums[midIndex] == target) {
            return midIndex;
        } else {
            return -1;
        }
    }
};