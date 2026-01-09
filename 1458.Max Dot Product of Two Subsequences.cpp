/*
 * @lc app=leetcode id=1458 lang=cpp
 * @lcpr version=30305
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int currentProduct = nums1[i - 1] * nums2[j - 1];
                dp[i][j] = dp[i - 1][j];
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] =
                    max(dp[i][j], max(0, dp[i - 1][j - 1]) + currentProduct);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,-2,5]\n[3,0,-6]\n
// @lcpr case=end

// @lcpr case=start
// [3,-2]\n[2,-6,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1]\n[1,1]\n
// @lcpr case=end

 */

