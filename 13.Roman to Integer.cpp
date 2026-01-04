/*
 * @lc app=leetcode id=13 lang=cpp
 * @lcpr version=30305
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map < char  , int > mp;
        mp['I'] = 1 , mp['V'] = 5 , mp['X'] = 10 , mp['L'] = 50 , mp['C'] = 100 , mp['D'] = 500 , mp['M'] = 1000;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(i + 1 < s.size() and mp[s[i]] < mp[s[i + 1]])
                ans -= mp[s[i]];
            else
                ans += mp[s[i]];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "LVIII"\n
// @lcpr case=end

// @lcpr case=start
// "MCMXCIV"\n
// @lcpr case=end

 */

