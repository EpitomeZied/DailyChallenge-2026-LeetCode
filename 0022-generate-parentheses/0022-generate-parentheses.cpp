class Solution {

public:
    vector<string> generateParenthesis(int n) {
        n = 2 * n;
        vector<string> ans;

        function<bool(string)> valid = [](string ss) {
            stack<char> st;
            for (char c : ss) {
                if (c == '(')
                    st.push(c);
                else {
                    if (st.empty())
                        return false;
                    st.pop();
                }
            }
            return st.empty();
        };

        string s;
        function<void(int)> rec = [&](int i) {
            if (i == n) {
                if (valid(s))
                    ans.push_back(s);
                // cout << s << endl;
                return;
            }
            // close bracket
            s.push_back(')');
            rec(i + 1);
            s.pop_back();
            // open bracket
            s.push_back('(');
            rec(i + 1);
            s.pop_back();
        };
        rec(0);
        return ans;
    }
};