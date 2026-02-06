class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1);
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            // pref[i] = pref[i - 1] + nums[i];
            pref[i + 1] = (pref[i] + nums[i]) % k;
            if (st.count(pref[i + 1])) return true;
            st.insert(pref[i]); // Len != 1;
        }
        return false;
    }
};
