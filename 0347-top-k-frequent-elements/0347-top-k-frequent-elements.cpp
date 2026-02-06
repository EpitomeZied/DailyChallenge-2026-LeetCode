class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (int it: nums) mp[it]++;

        priority_queue<pair<int, int> > pq;

        for (auto &[x , y]: mp) {
            pq.emplace(-y, x);
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
