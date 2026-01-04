/*
 * @lc app=leetcode id=21 lang=cpp
 * @lcpr version=30305
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 or !list2) return list1 ? list1 : list2;
        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next , list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1 , list2->next);
        return list2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

