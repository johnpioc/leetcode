class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);

        string word1;
        string word2;

        while (ss1.peek() != char_traits<char>::eof() || ss2.peek() != char_traits<char>::eof()) {
            if (ss1.peek() == char_traits<char>::eof()) word1 = "0";
            else getline(ss1, word1, '.');
            if (ss2.peek() == char_traits<char>::eof()) word2 = "0";
            else getline(ss2, word2, '.');

            int num1 = stoi(word1);
            int num2 = stoi(word2);

            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
        }

        return 0;
    }
};
