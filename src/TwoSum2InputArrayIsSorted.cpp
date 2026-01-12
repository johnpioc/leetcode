class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;

        int currentNumber = numbers[leftIndex] + numbers[rightIndex];

        while (currentNumber != target) {
            if (currentNumber < target) {
                leftIndex++;
            } else {
                rightIndex--;
            }

            currentNumber = numbers[leftIndex] + numbers[rightIndex];
        }

        vector<int> output(2);

        output[0] = leftIndex + 1;
        output[1] = rightIndex + 1;

        return output;
    }
};