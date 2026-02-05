class Solution {
public:
    char getChar(int number) {
        switch (number) {
            case 1: return 'I';
            case 5: return 'V';
            case 10: return 'X';
            case 50: return 'L';
            case 100: return 'C';
            case 500: return 'D';
            default: return 'M';
        }
    }
    string intToRoman(int num) {
        string numString = to_string(num);
        string output = "";

        for (int i = 0; i < numString.size(); i++) {
            int currentDigit = numString[i] - '0';
            int magnitude = numString.size() - i - 1;

            if (currentDigit == 4) {
                output += getChar(pow(10, magnitude));
                output += getChar(5 * pow(10, magnitude));
            } else if (currentDigit == 9) {
                output += getChar(pow(10, magnitude));
                output += getChar(pow(10, magnitude + 1));
            } else {
                if (currentDigit >= 5) {
                    output += getChar(5 * pow(10, magnitude));
                    currentDigit -= 5;
                }

                while (currentDigit-- > 0) {
                    output += getChar(pow(10, magnitude));
                }
            }
        }

        return output;
    }
};