class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 51;
        int l = 0;
        int current_or = 0;
        vector<int> cnt(32, 0);

        auto add = [&](int x) {
            for (int b = 0; b < 32; b++) {
                if (x & (1 << b)) {
                    cnt[b]++;
                    current_or |= (1 << b);
                }
            }
        };

        auto remove = [&](int x) {
            for (int b = 0; b < 32; b++) {
                if (x & (1 << b)) {
                    cnt[b]--;
                    if (cnt[b] == 0) {
                        current_or &= ~(1 << b);
                    }
                }
            }
        };

        for (int r = 0; r < n; r++) {
            add(nums[r]);

            while (l <= r && current_or >= k) {
                ans = min(ans, r - l + 1);
                remove(nums[l]);
                l++;
            }
        }

        return ans == 51 ? -1 : ans;
    }
};