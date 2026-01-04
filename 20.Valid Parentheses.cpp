/*
 * @lc app=leetcode id=20 lang=cpp
 * @lcpr version=30305
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
  char leftOf(char c) {
    if (c == ')')
      return '(';
    if (c == '}')
      return '{';
    return '[';
  }
  bool isValid(string str) {
    stack<char> left;
    for (char c : str) {
      if (c == '(' || c == '{' || c == '[') {
        left.push(c);
      } else {
        if (!left.empty() && leftOf(c) == left.top()) {
          left.pop();
        } else {
          return false;
        }
      }
    }
    return left.empty();
  }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */
