class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int e =0  , mx_len = 0;
        priority_queue<pair < int , int > > mx , mn;
        for (int s = 0; s < nums.size(); s++) {
            mx.push({nums[s], s});
            mn.push({-1 * nums[s], s});
            while (mx.top().first - -1 * mn.top().first > limit) {
                e = min(mx.top().second, mn.top().second) + 1;

                while (mx.top().second < e) {
                    mx.pop();
                }
                while (mn.top().second < e) {
                    mn.pop();
                }
            }
            mx_len = max(mx_len, s - e + 1);
        }
        return mx_len;
    }
};