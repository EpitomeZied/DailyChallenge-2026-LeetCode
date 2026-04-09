class Solution {
private:
    vector<string> ans;
    string s;

    void build(int open_rem, int open_cnt) {
        if (open_cnt < 0)
            return;
        if (open_rem == 0) {
            for (int i = open_cnt; i > 0; i--)
                s += ')';
            ans.push_back(s);
            for (int i = open_cnt; i > 0; i--)
                s.pop_back();

            return;
        }
        s += '(';
        build(open_rem - 1, open_cnt + 1); // open
        s.pop_back();
        s += ")";
        build(open_rem, open_cnt - 1); // close
        s.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {
        build(n, 0);
        return ans;
    }
};