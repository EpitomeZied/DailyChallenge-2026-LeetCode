class Solution {
public:
    string longestPalindrome(string s) {
        int sz = 1;
        string ans;
        ans = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                // even size 
                int l = i - 2, r = i + 1;
                while (0 <= l and r < s.size() and s[l] == s[r]) {
                    if (r - l + 1 > sz) {
                        sz = r - l + 1;
                        ans = s.substr(l, sz);
                    }
                    l--, r++;
                }
                if (sz <= 2)
                    ans = s.substr(i - 1, 2);
                sz = max(sz, 2);
            }
            // odd size
            int l = i - 1, r = i + 1;
            while (0 <= l and r < s.size() and s[l] == s[r]) {
                if (r - l + 1 > sz) {
                    sz = r - l + 1;
                    ans = s.substr(l, sz);
                }
                l--, r++;
            }
        }
        return ans;
    }
};