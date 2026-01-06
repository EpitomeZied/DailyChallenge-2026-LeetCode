/*
 * @lc app=leetcode id=1161 lang=cpp
 * @lcpr version=30305
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 0 ; 
        int level = 0 ; 
        int maxSum = INT_MIN; 
        queue<TreeNode*> q ; 
        q.push(root) ; // bfs
        while(!q.empty()){
            int size = q.size() ; 
            int sum = 0 ; 
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front() ; 
                q.pop() ; 
                sum += node->val ; 
                if(node->left) q.push(node->left) ;
                if(node->right) q.push(node->right) ;
            }
            if(sum > maxSum){
                maxSum = sum ; 
                ans = level ; 
            }
            level++; 
        }
        return ans + 1 ; 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,0,7,-8,null,null]\n
// @lcpr case=end

// @lcpr case=start
// [989,null,10250,98693,-89388,null,null,null,-32127]\n
// @lcpr case=end

 */

