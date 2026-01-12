class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> seen;
        
        for (int num : nums) {
            seen.insert(num);
        }

        set<int> evaluated;

        int longestLength = 0;
        for (int num : nums) {
            if (evaluated.contains(num)) continue;

            bool isStartOfSequence = !seen.contains(num - 1);

            if (isStartOfSequence) {
                int currentLength = 1;
                int currentNum = num + 1;
                
                while (seen.contains(currentNum++)) currentLength++;

                if (currentLength > longestLength) {
                    longestLength = currentLength;
                }
            }

            evaluated.insert(num);
        }

        return longestLength;
    }
};