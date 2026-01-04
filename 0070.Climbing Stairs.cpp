/*
 * @lc app=leetcode id=70 lang=cpp
 * @lcpr version=30305
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
  vector<int> memo;

  int climbStairs(int n) {
    memo.resize(n + 1, 0);
    return dp(n);
  }

  int dp(int n) {
    if (n <= 2) {
      return n;
    }
    if (memo[n] > 0) {
      return memo[n];
    }
    memo[n] = dp(n - 1) + dp(n - 2);
    return memo[n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
