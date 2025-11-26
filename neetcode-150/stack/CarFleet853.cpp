class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<array<int,2>> cars(position.size());

        for (int i = 0; i < position.size(); i++) {
            cars[i] = { position[i], speed[i] };
        }

        sort(cars.begin(), cars.end(), [](array<int,2> a, array<int,2> b) {
            return a[0] > b[0];
        });

        stack<float> decreasingStack;

        int numOfFleets = 0;
        for (int i = 0; i < position.size(); i++) {
            float currentTime = (double) (target - cars[i][0]) / cars[i][1];

            while (decreasingStack.size() > 0 && decreasingStack.top() < currentTime) decreasingStack.pop();

            if (decreasingStack.size() == 0) {
                numOfFleets++;
            }

            decreasingStack.push(currentTime);
        }

        return numOfFleets;
    }
};