class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3)
            return ans;

        sort(nums.begin(), nums.end());

        unordered_map<int, int> cnt;
        cnt.reserve(n * 2);
        for (int x : nums)
            cnt[x]++;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // skip dup i
            cnt[nums[i]]--;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // skip dup j
                cnt[nums[j]]--;

                int target = -nums[i] - nums[j];

                // enforce canonical order: nums[i] <= nums[j] <= target
                if (target >= nums[j] && cnt[target] > 0) {
                    ans.push_back({nums[i], nums[j], target});
                }

                cnt[nums[j]]++;
            }

            cnt[nums[i]]++;
        }

        return ans;
    }
};