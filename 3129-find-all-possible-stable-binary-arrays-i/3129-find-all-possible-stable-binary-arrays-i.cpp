class Solution {
public:
    static const int MOD = 1e9 + 7;
    int limit;
    vector<vector<vector<vector<int>>>> memo;

    int solve(int zero, int one, int last, int cnt) {
        if (zero == 0 && one == 0) return 1;

        int &ret = memo[zero][one][last][cnt];
        if (ret != -1) return ret;

        ret = 0;

        if (last == 0) {
            if (zero > 0 && cnt < limit) {
                ret = (ret + solve(zero - 1, one, 0, cnt + 1)) % MOD;
            }
            if (one > 0) {
                ret = (ret + solve(zero, one - 1, 1, 1)) % MOD;
            }
        } else {
            if (one > 0 && cnt < limit) {
                ret = (ret + solve(zero, one - 1, 1, cnt + 1)) % MOD;
            }
            if (zero > 0) {
                ret = (ret + solve(zero - 1, one, 0, 1)) % MOD;
            }
        }

        return ret;
    }

    int numberOfStableArrays(int zero, int one, int lim) {
        limit = lim;
        memo.assign(zero + 1,
            vector<vector<vector<int>>>(one + 1,
                vector<vector<int>>(2,
                    vector<int>(limit + 1, -1))));

        int ans = 0;
        if (zero > 0) ans = (ans + solve(zero - 1, one, 0, 1)) % MOD;
        if (one > 0) ans = (ans + solve(zero, one - 1, 1, 1)) % MOD;

        return ans;
    }
};