class Solution {
public:
    int numSteps(string s) {
        s = '0' + s;

        auto lastOne = find(s.begin(), s.end(), '1');
        int l = distance(s.begin(), lastOne);
        int r = s.size() - 1;

        int steps = 0;

        while (l < r) {
            if (s[r] == '1') {
                int i = r;
                while (i >= l && s[i] == '1') {
                    s[i--] = '0';
                }

                if (i < l) l = i;
                s[i] = '1';
            } else {
                r--;
            }

            steps++;
        }

        return steps;
    }
};