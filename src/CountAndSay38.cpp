class Solution {
public:
    unordered_map<int, string> cache;

    string countAndSay(int n) {
        if (n == 1) return "1";
        else return build("1", 2, n);
    }

    string build(string rle, int index, int target) {
        string result;

        if (cache.contains(index)) result = cache[index];
        else {
            int count = 0;
            char currentChar = rle[0];

            for (int i = 0; i < rle.size(); i++) {
                if (rle[i] != currentChar) {
                    result += to_string(count) + currentChar;
                    count = 1;
                    currentChar = rle[i];
                } else {
                    count++;
                }
            }

            result += to_string(count) + currentChar;

            cache[index] = result;
        }

        if (index != target) return build(result, index + 1, target);
        else return result;
    }
};