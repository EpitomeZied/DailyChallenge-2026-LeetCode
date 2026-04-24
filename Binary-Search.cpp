1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int l = 0 , r = nums.size() - 1;
5        while(l <= r){
6            int md = (l + r) / 2;
7            if(nums[md] == target) return md;
8            if(nums[md] > target) r = md - 1;
9            else l = md + 1;
10        }
11        return -1;
12    }
13};