class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0) return 0.0;
        if (n == 0) return 1.0;

        double result = 1;
        long power = abs((long)n);

        while (power) {
            if (power & 1) {
                result *= x;
            }

            x *= x;
            power >>= 1;
        }

        return n >= 0 ? result : 1 / result;
    }
};