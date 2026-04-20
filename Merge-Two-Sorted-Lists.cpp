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
13    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
14        if (!list1)
15            return list2;
16        if (!list2)
17            return list1;
18
19        ListNode *h = nullptr, *t = nullptr;
20        if (list1->val <= list2->val) {
21            h = t = list1;
22            list1 = list1->next;
23        } else {
24            h = t = list2;
25            list2 = list2->next;
26        }
27
28        while (list1 and list2) {
29            if (list1->val <= list2->val) {
30                if (t == nullptr)
31                    t = list1;
32                else {
33                    t->next = list1;
34                    t = t->next;
35                }
36                list1 = list1->next;
37
38            } else {
39                if (t == nullptr)
40                    t = list2;
41                else {
42                    t->next = list2;
43                    t = t->next;
44                }
45                list2 = list2->next;
46            }
47        }
48        if (!list1)
49            list1 = list2;
50        while (list1) {
51            t->next = list1;
52            t = t->next;
53            list1 = list1->next;
54        }
55        return h;
56    }
57};