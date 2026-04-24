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
13    ListNode* reverseList(ListNode* head) {
14        ListNode* previousNode = nullptr;
15        ListNode* currentNode = head;
16        while (currentNode != nullptr) {
17            ListNode* nextNode = currentNode->next;
18            currentNode->next = previousNode;
19            previousNode = currentNode;
20            currentNode = nextNode;
21        }
22        return previousNode;
23    }
24};