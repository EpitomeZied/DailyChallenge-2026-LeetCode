/*
 * @lc app=leetcode id=14 lang=cpp
 * @lcpr version=30305
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string s1 = strs[0]  , s2 = strs.back(); // min , max string size;
        int i = 0;
        while(i < s1.size() and i < s2.size() and s1[i] == s2[i]) i++;
        return s1.substr(0 , i);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */

