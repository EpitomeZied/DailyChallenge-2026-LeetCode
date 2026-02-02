class Solution {
public:
    long long minimumCost(vector<int> &nums, int k, int dist) {
        int n = (int) nums.size();

        --k;
        if (k == 0) return nums[0];

        if (k == 1) {
            int mn = INT_MAX;
            for (int i = 1; i < n; i++) mn = min(mn, nums[i]);
            return (long long) nums[0] + mn;
        }

        int need = k - 1;

        multiset<int> l;
        multiset<int> r;
        long long sumLeft = 0;
        auto rebalance = [&]() {
            while ((int) l.size() > need) {
                auto it = prev(l.end());
                sumLeft -= *it;
                r.insert(*it);
                l.erase(it);
            }
            while ((int) l.size() < need && !r.empty()) {
                auto it = r.begin();
                sumLeft += *it;
                l.insert(*it);
                r.erase(it);
            }
            while (!l.empty() && !r.empty() && *prev(l.end()) > *r.begin()) {
                auto itL = prev(l.end());
                auto itR = r.begin();
                int a = *itL, b = *itR;

                sumLeft -= a;
                sumLeft += b;

                l.erase(itL);
                r.erase(itR);

                l.insert(b);
                r.insert(a);
            }
        };

        auto addVal = [&](int x) {
            if (!l.empty() && x <= *prev(l.end())) {
                l.insert(x);
                sumLeft += x;
            } else {
                r.insert(x);
            }
            rebalance();
        };

        auto removeVal = [&](int x) {
            auto itL = l.find(x);
            if (itL != l.end()) {
                sumLeft -= x;
                l.erase(itL);
            } else {
                auto itR = r.find(x);
                if (itR != r.end()) r.erase(itR);
            }
            rebalance();
        };

        int L = 1;
        int R = min(n - 1, L + dist);
        for (int i = L + 1; i <= R; i++) r.insert(nums[i]);
        rebalance();
        long long ans = LLONG_MAX;

        for (L = 1; L <= n - 1; L++) {
            int winSize = (int) l.size() + (int) r.size();

            if (winSize >= need) {
                ans = min(ans, (long long) nums[0] + nums[L] + sumLeft);
            }

            int outIdx = L + 1;
            if (outIdx <= n - 1) removeVal(nums[outIdx]);

            int inIdx = L + dist + 1;
            if (inIdx <= n - 1) addVal(nums[inIdx]);
        }
        return ans;
    }
};