1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* deleteDuplicates(ListNode* head) {
14        ListNode *h = head;
15        while(head && head->next) {
16            if(head->val == head->next->val) {
17                ListNode *Dummy = head->next->next;
18                delete head->next;
19                head->next = Dummy;
20            }
21            else {
22                head = head->next;
23            }
24        }
25        return h;
26    }
27};