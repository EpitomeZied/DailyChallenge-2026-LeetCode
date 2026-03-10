class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int r = 0, mx_len = 0;
        priority_queue<pair<int, int>> mx, mn;
        for (int l = 0; l < nums.size(); l++) {
            mx.push({nums[l], l});
            mn.push({-1 * nums[l],l});
            while (mx.top().first - -1 * mn.top().first > limit) {
                r = min(mx.top().second, mn.top().second) + 1;

                while (mx.top().second < r) {
                    mx.pop();
                }

                while (mn.top().second < r) {
                    mn.pop();
                }

            }
            mx_len = max(mx_len, l - r + 1);
        }
        return mx_len;
    }
};