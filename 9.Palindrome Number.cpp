/*
 * @lc app=leetcode id=9 lang=cpp
 * @lcpr version=30305
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        for(int i = 0; i < s.size() / 2; i++)
            if(s[i] != s[s.size() - i - 1]) return false;
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

