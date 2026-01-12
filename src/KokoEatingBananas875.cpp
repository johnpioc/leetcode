class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxNum = piles[0];

        for (int i = 1; i < piles.size(); i++) {
            maxNum = max(maxNum, piles[i]);
        }

        return binarySearch(piles, 1, maxNum, h);
    }

    int binarySearch(vector<int>& piles, int l, int r, int h) {
        if (l > r) return INT_MAX;

        int mid = (l + r) / 2;
        long numOfHours = 0;
        for (int pile : piles) {
            numOfHours += ceil((double)pile / mid);
        }

        if (numOfHours > h) {
            return binarySearch(piles, mid + 1, r, h);
        } else {
            return min(mid, binarySearch(piles, l, mid - 1, h));
        }
    }
};