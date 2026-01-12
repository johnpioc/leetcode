class Solution {
public:
    int getNumber(int n) {
        int output = 0;
        
        while (n > 0) {
            int currentDigit = n % 10;
            n /= 10;
            output += pow(currentDigit, 2);
        }

        return output;
    }

    bool isHappy(int n) {
        set<int> visited;
        int sum = getNumber(n);

        while (!visited.contains(sum)) {
            if (sum == 1) {
                break;
            }

            visited.insert(sum);

            sum = getNumber(sum);            
        }

        if (sum == 1) {
            return true;
        } else {
            return false;
        }
    }
};