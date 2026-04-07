class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        std::string word;

        vector<string> collection;

        while (ss >> word) {
            collection.push_back(word);
        }

        string output = "";

        for (int i = collection.size() - 1; i >= 0; i--) {
            output += collection[i] + (i != 0 ? " " : "");
        }

        return output;
    }
};
