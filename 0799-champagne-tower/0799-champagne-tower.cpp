class Solution {
private:
    double rec(vector<vector<double>>& memo, int row, int glass) {
        if (row < 0 or glass < 0 or glass > row) {
            return 0;
        }

        if (memo[row][glass] != -1) {
            return memo[row][glass];
        }
        return memo[row][glass] = (max(0.0, rec(memo, row - 1, glass - 1) - 1) + max(0.0, rec(memo, row - 1, glass) - 1) ) / 2;
    }

public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> memo(query_row + 5);
        for (int i = 0; i <= query_row + 4; i++) {
            memo[i].resize(i + 1, -1);
        }

        memo[0][0] = poured;
        return min(1.0, rec(memo, query_row, query_glass));
    }
};