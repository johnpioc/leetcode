class Solution {
public:
    int myAtoi(string s) {
        int startIndex = 0;

        while (startIndex < s.size() && s[startIndex] == ' ') startIndex++;
        if ((startIndex == s.size() || s[startIndex] - '0' < 0 || s[startIndex] - '0' > 9)
            && (startIndex < s.size() && s[startIndex] != '-' && s[startIndex] != '+')) return 0;

        int endIndex = (s[startIndex] == '-' || s[startIndex] == '+') ? startIndex + 1 : startIndex;
        if (s[endIndex] - '0' < 0 || s[endIndex] - '0' > 9) return 0;
        while (endIndex + 1 < s.size() && (s[endIndex + 1] - '0') >= 0 && (s[endIndex + 1] - '0') <= 9)
            endIndex++;

        int res = 0;
        for (int i = endIndex; i >= startIndex; i--) {
            if (s[i] == '-') {
                res *= -1;
                break;
            } else if (s[i] == '+') break;

            int number = s[i] - '0';
            if (number == 0) continue;
            if (endIndex - i >= 10)
                return s[startIndex] == '-' ? INT_MIN : INT_MAX;

            int magnitude = pow(10, endIndex - i);

            if (number > INT_MAX / magnitude) 
                return s[startIndex] == '-' ? INT_MIN : INT_MAX;

            if (res > INT_MAX - number * magnitude)
                return s[startIndex] == '-' ? INT_MIN : INT_MAX;

            res += number * magnitude;
        }

        return res;
    }
};