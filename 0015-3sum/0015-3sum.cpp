class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // ! n^2(logn) -> TLE
    // map < int , int > mp;
    // set < vector < int > > ans;
    // for(auto it : nums) mp[it]++;
    // for(int i = 0 ; i < nums.size() ; i++) { // O(n)
    //     for(int j = i + 1 ; j < nums.size() ; j++) { // O(n)
    //         int target = -1 * (nums[i] + nums[j]);
    //         if(mp.count(target)) { // O(logn)
    //             if(nums[i] == target && mp[nums[i]] <= 2) continue;
    //             if(nums[j] == target && mp[nums[j]] <= 2) continue;
    //             vector < int > temp = { {nums[i] , nums[j] , target}};
    //             sort(temp.begin(), temp.end());
    //             ans.insert(temp);
    //         }
    //     }
    // }
    // vector<vector<int>> ret;
    // for(auto it : ans) ret.push_back(it);
    // return ret;
    // ! nlogn -> Two Pointers

    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ans.push_back({nums[i], nums[l], nums[r]});
          l++;
          r--;
          while (l < r && nums[l] == nums[l - 1])
            l++;
          while (l < r && nums[r] == nums[r + 1])
            r--;
        } else if (sum < 0) {
          l++;
        } else {
          r--;
        }
      }
    }
    return ans;
  }
};