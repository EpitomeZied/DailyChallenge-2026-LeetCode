class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(s[i])) {
                mp[s[i]] = 1e5 + 5;
            } else {
                mp[s[i]] = i;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (mp[s[i]] != 1e5 + 5) {
                return mp[s[i]];
            }
        }
        return -1;
    }
};