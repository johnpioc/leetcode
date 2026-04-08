class Solution {
private:
    int code(char c) {
        if (c == 'A') return 0;
        else if (c == 'C') return 1;
        else if (c == 'G') return 2;
        else return 3;
    }

    char translate(int code) {
        if (code == 0) return 'A';
        else if (code == 1) return 'C';
        else if (code == 2) return 'G';
        else return 'T';
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return { };

        unsigned int curr = 0;
        unsigned int mask = (1u << 20) - 1;
        for (int i = 0; i < 10; i++) {
            curr <<= 2;
            curr |= code(s[i]);
        }
        curr &= mask;

        unordered_map<int, bool> found;
        found[curr] = false;

        for (int i = 10; i < s.size(); i++) {
            curr <<= 2;
            curr |= code(s[i]);
            curr &= mask;

            if (!found.contains(curr)) {
                found[curr] = false;
            } else {
                found[curr] = true;
            }
        }

        vector<string> output;
        unsigned int bitMask = 3 << 18;
        for (const auto& [key, value] : found) {
            if (value) {
                int keyCopy = key;
                string result = "";
                for (int i = 0; i < 10; i++) {
                    result += translate((keyCopy & bitMask) >> 18);
                    keyCopy <<= 2;
                }
                output.push_back(result);
            }
        }

        return output;
    }
};
