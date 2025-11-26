class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        
        while (n > 0) {
            if (n % 2 == 1) result++;
            n /= 2;
        }

        return result;  
    }
};