#include <set>
#import <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;
        bool containsDup = false;

        for (int i = 0; i < nums.size(); i++) {
            if (seen.contains(nums[i])) {
                containsDup = true;
                break;
            } else {
                seen.insert(nums[i]);
            }
        }

        return containsDup;
    }
};