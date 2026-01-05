/*
 * @lc app=leetcode id=1975 lang=cpp
 * @lcpr version=30305
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
#define ll long long
class Solution {
public:
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum = 0;
        ll minAbs = LLONG_MAX;
        ll negativeCount = 0;

        for (const auto& row : matrix) {
            for (ll val : row) {
                if (val < 0) negativeCount++;
                ll absVal = abs(val);
                sum += absVal;
                minAbs = min(minAbs, absVal);
            }
        }

        if (negativeCount % 2 == 1) {
            sum -= 2 * minAbs;
        }

        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,-1],[-1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[-1,-2,-3],[1,2,3]]\n
// @lcpr case=end

 */

