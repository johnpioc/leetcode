class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> cardCounts;
        for (int card : hand) {
            cardCounts[card]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> cards;

        for (const auto& [card, count] : cardCounts) {
            cards.push({ card, count });
        }

        while (cards.size() > 0) {
            stack<pair<int,int>> taken;
            taken.push(cards.top());
            cards.pop();

            int difference = -1;
            for (int j = 0; j < groupSize - 1; j++) {
                if (cards.size() == 0) return false;
                pair<int,int> current = cards.top();
                if (current.first - taken.top().first != 1) return false;
                taken.push(current);
                cards.pop();
            }

            while (taken.size() > 0) {
                if (taken.top().second > 1) {
                    cards.push({ taken.top().first, taken.top().second - 1 });
                }

                taken.pop();
            }
        }

        return cards.size() == 0;
    }
};