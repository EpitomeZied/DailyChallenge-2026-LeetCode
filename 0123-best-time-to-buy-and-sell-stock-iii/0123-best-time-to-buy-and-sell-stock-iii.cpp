class Solution {
public:
    int n;
    vector<int> p;
    vector<vector<vector<int>>> memo;
    vector<vector<vector<char>>> vis;

    int dfs(int i, int holding, int k) {
        if (i == n) return 0;
        if (k == 0) return 0;

        if (vis[i][holding][k]) return memo[i][holding][k];
        vis[i][holding][k] = 1;

        int best = dfs(i + 1, holding, k); // skip

        if (holding == 0) {
            // buy
            best = max(best, -p[i] + dfs(i + 1, 1, k));
        } else {
            // sell
            best = max(best, p[i] + dfs(i + 1, 0, k - 1));
        }

        return memo[i][holding][k] = best;
    }

    int maxProfit(vector<int>& prices) {
        p = prices;
        n = (int)p.size();
        memo.assign(n, vector<vector<int>>(2, vector<int>(3, 0)));
        vis.assign(n, vector<vector<char>>(2, vector<char>(3, 0)));
        return dfs(0, 0, 2);
    }
};
