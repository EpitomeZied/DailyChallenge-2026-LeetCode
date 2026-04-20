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
13    ListNode* removeNthFromEnd(ListNode* head, int n) {
14        ListNode* slow = head;
15        ListNode* fast = head;
16        ListNode* prv = nullptr;
17        for (int i = 0; i < n; ++i) {
18            if (fast == nullptr) {
19                return head;
20            }
21            fast = fast->next;
22        }
23
24        if (fast == nullptr) {
25            head = head->next;
26            return head;
27        }
28
29        while (fast != nullptr) {
30            prv = slow;
31            slow = slow->next;
32            fast = fast->next;
33        }
34        prv->next = slow->next;
35        return head;
36    }
37};