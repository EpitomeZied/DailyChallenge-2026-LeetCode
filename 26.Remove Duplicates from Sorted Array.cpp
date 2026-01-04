/*
 * @lc app=leetcode id=26 lang=cpp
 * @lcpr version=30305
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto nwarr = nums;
        sort(nwarr.begin() , nwarr.end());
        nwarr.erase(unique(nwarr.begin() , nwarr.end()) , nwarr.end());
        nums = nwarr;
        return nwarr.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

