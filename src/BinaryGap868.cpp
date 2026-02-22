class Solution {
public:
    int binaryGap(int n) {
        int largestGap = 0;
        bool foundOne = false;
        int current = 0;

        while (n > 0) {
            if (n % 2 == 0) current++;
            else {
                if (!foundOne) {
                    foundOne = true;
                } else {
                    largestGap = max(current, largestGap);
                }

                current = 1;
            }

            n /= 2;
        }

        return largestGap;
    }
};