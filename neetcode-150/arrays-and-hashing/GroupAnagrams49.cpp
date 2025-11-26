class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramsMap;

        for (string word : strs) {
            string sortedString = word;
            sort(sortedString.begin(), sortedString.end());
            anagramsMap[sortedString].push_back(word);  
        }

        vector<vector<string>> anagrams;

        for (const auto& [key, value]: anagramsMap) {
            anagrams.push_back(value);
        }

        return anagrams;
    }
};