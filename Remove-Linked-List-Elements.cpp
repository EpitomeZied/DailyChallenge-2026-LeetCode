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
13    ListNode* removeElements(ListNode* head, int val) {
14        ListNode* dummy = new ListNode(0, head);
15        ListNode* current = dummy;
16
17        while (current->next) {
18            if (current->next->val == val) {
19                ListNode* temp = current->next;
20                current->next = temp->next;
21                delete temp;
22            } else {
23                current = current->next;
24            }
25        }
26        return dummy->next;
27    }
28};