/*
 * @lc app=leetcode id=961 lang=cpp
 * @lcpr version=30305
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {
    vector<int> count(10001, 0);
    for (int i = 0; i < nums.size(); i++) {
      count[nums[i]]++;
      if (count[nums[i]] > 1) {
        return nums[i];
      }
    }
    return -1;
  }
};

// @lc code=end

/*
// @lcpr case=start
// [1,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,2,5,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,5,2,5,3,5,4]\n
// @lcpr case=end

 */
