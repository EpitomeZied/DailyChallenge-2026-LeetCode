/*
 * @lc app=leetcode id=58 lang=cpp
 * @lcpr version=30305
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool seen = false; 
        int ans = 0;
        for(int i = s.size() - 1 ; i >= 0 ; i--){
            if(s[i] == ' ' and seen) return ans;
            if(s[i] != ' ') seen = true , ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */

