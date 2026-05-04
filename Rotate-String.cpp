1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        if (s.length() != goal.length()) return false;
5        string doubledString = s + s;
6        return doubledString.find(goal) < doubledString.length();
7    }
8};