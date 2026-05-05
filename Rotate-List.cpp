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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if (!head || !head->next) {
15            return head;
16        }
17      
18        ListNode* current = head;
19        int length = 0;
20        while (current) {
21            ++length;
22            current = current->next;
23        }
24      
25        k %= length;
26      
27        if (k == 0) {
28            return head;
29        }
30      
31        ListNode* fastPointer = head;
32        ListNode* slowPointer = head;
33        
34        while (k--) {
35            fastPointer = fastPointer->next;
36        }
37      
38        while (fastPointer->next) {
39            fastPointer = fastPointer->next;
40            slowPointer = slowPointer->next;
41        }
42      
43        ListNode* newHead = slowPointer->next;
44      
45        slowPointer->next = nullptr;
46      
47        fastPointer->next = head;
48      
49        return newHead;
50
51    }
52};