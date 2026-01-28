class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        bool flag = false;
        do {
            for (int i = 0; i < nums.size(); ++i) {
                nums[i] = nums[i];
            }
            if (flag) break;
            flag = true;
        } while (next_permutation(nums.begin(), nums.end()));
    }
};
