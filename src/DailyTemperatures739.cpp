class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<array<int,2>> decreasingStack;
        vector<int> output(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            array<int, 2> currentTemp = { temperatures[i], i }; 
            
            while (decreasingStack.size() > 0 && currentTemp[0] >= decreasingStack.top()[0]) {
                decreasingStack.pop();
            }

            if (decreasingStack.size() == 0) {
                output[i] = 0;
            } else {
                int topTemp[] = { decreasingStack.top()[0], decreasingStack.top()[1] };
                output[i] = topTemp[1] - i;
            }
            
            decreasingStack.push(currentTemp);
        }

        return output;
    }
};