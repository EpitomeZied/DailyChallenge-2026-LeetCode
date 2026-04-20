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
13    int getDecimalValue(ListNode* head) {
14        int num = 0;
15        ListNode* current = head;
16        while (current != nullptr) {
17            num = num * 2 + current->val;
18            current = current->next;
19        }
20        return num;
21    }
22};