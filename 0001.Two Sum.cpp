/*
 * @lc app=leetcode id=1 lang=cpp
 * @lcpr version=30305
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      if (mp.count(target - nums[i]))
        return {mp[target - nums[i]], i};
      mp[nums[i]] = i;
    }
    return {};
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
