/*
 * @lc app=leetcode id=5 lang=cpp
 * @lcpr version=30305
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      string s2 , s1 = palindrome(s, i, i);
      if (i + 1 < s.size() and s[i] == s[i + 1])
        s2 = palindrome(s, i, i + 1);
      res = res.length() > s1.length() ? res : s1;
      res = res.length() > s2.length() ? res : s2;
    }
    return res;
  }

private:
  string palindrome(string s, int l, int r) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
      l--;
      r++;
    }
    return s.substr(l + 1, r - l - 1);
  }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
