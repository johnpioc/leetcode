class Solution {
public:
    int reverseBits(int n) {
        string bitString = "";

        for (int i = 0; i < 32; ++i) {
            bitString += (n % 2 == 1) ? '1' : '0';
            n /= 2;
        }

        int result = 0;
        for (int exp = 0; exp < bitString.size(); exp++) {
            int index = bitString.size() - exp - 1;

            if (bitString[index] == '1') result += pow(2, exp);
        }

        return result;
    }
};