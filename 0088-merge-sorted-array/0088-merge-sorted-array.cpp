class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> nums3;
        nums3.swap(nums1);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums3[i] <= nums2[j]) {
                nums1.push_back(nums3[i++]);
            } else {
                nums1.push_back(nums2[j++]);
            }
        }
        while (i < m) nums1.push_back(nums3[i++]);
        while (j < n) nums1.push_back(nums2[j++]);
    }
};
