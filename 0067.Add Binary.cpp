/*
 * @lc app=leetcode id=67 lang=cpp
 * @lcpr version=30305
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
  string addBinary(string a, string b) {
    string res = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 or j >= 0 or carry) {
      int sum = carry;
      if (i >= 0)
        sum += a[i--] - '0';
      if (j >= 0)
        sum += b[j--] - '0';

      res.push_back((sum % 2) + '0');
      carry = sum / 2;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */
