1class Solution {
2public:
3    bool areOccurrencesEqual(string s) {
4        map < char , int> mp;
5        for(auto ch : s) {
6            mp[ch]++;
7        }
8        int x = mp[s[0]];
9        for(auto [_ , it] : mp) {
10            if(it != x) return false;
11        }
12        return true;
13    }
14};