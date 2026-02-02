class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> work;
        for (const string& it : strs) {
            string sorted_word = it;
            sort(sorted_word.begin(), sorted_word.end());
            work[sorted_word].push_back(it);
        }
        vector<vector<string>> ans;
        for (auto const& [_, it] : work) {
            ans.push_back(it);
        }
        return ans;
    }
};