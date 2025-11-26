class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            int currentNumber = digits[i];

            if (currentNumber == 9) {
                if (i == 0) {
                    digits[i] = 1;
                    digits.push_back(0);
                } else {
                    digits[i] = 0;
                }
                
            } else {
                digits[i] += 1;
                break;
            }
        }

        return digits;
    }
};