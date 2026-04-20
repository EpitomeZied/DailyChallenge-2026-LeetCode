1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
12        ListNode* a = headA;
13        ListNode* b = headB;
14
15        while (a != b) { // 3 + 5 = 5 + 3;
16            a = (a == nullptr) ? headB : a->next;
17            b = (b == nullptr) ? headA : b->next;
18        }
19
20        return a;
21    }
22};