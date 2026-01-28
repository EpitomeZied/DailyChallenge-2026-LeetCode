class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        unordered_map<int, unordered_set<char> > rows, cols;
        map<pair<int, int>, unordered_set<char> > squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                auto cur = board[r][c];
                if (cur == '.') continue;
                pair<int, int> sq = {r / 3, c / 3};
                if (rows[r].count(cur) or cols[c].count(cur) or squares[sq].count(cur))
                    return false;
                rows[r].insert(cur), cols[c].insert(cur), squares[sq].insert(cur);
            }
        }
        return true;
    }
};