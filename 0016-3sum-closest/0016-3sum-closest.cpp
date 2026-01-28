class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1e9;
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int cur = nums[l] + nums[r] + nums[i];
                if (cur == target)
                    return cur;
                if (abs(cur - target) < abs(ans - target)) {
                    ans = cur;
                }
                if (cur > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};