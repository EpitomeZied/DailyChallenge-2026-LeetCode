/*
 * @lc app=leetcode id=4 lang=cpp
 * @lcpr version=30305
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0 ; i < nums2.size() ; i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int n = nums1.size();
        if(n%2==0){
            return (nums1[n/2-1]+nums1[n/2])/2.0;
        }
        else{
            return nums1[n/2];
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

