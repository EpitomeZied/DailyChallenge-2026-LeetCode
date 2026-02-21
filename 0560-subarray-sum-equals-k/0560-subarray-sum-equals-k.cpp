class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, curSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (auto& num : nums) {
            curSum += num;
            ans += mp[ curSum - k];
            mp[curSum]++;
        }

        return ans;
    }
};