class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            int len = min(height[l], height[r]), w = r - l;
            ans = max(ans, len * w);
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};
