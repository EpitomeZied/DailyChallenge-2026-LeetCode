class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n + 1, -1));

        function<int(int, int)> rec = [&](int idx, int last_taken_idx) {
            if (idx == n)
                return 0;

            int& ret = mem[idx][last_taken_idx + 1];
            if (ret != -1)
                return ret;

            int ans = rec(idx + 1, last_taken_idx);

            if (last_taken_idx == -1 || nums[idx] > nums[last_taken_idx]) {
                ans = max(ans, 1 + rec(idx + 1, idx));
            }

            return ret = ans;
        };
        return rec(0, -1);
    }
};