class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n) , pref(n) , suff(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] * pref[i - 1];
        }
        suff[n - 1] = nums[n- 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i] * suff[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (i == n - 1)
                ans[i] = pref[n - 2];
            else if (i == 0)  ans[i] = suff[1];
            else
                ans[i] = pref[i - 1] * suff[i + 1];
        }
        return ans;
    }
};