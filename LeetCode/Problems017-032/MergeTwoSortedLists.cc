// Title:  Merge Two Sorted Lists
// Language: C++
// Runtime: 9 ms
// Submitted: 2016/11/6

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode *ans = new ListNode(0);
		ListNode *h = ans;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				ListNode *tmp = new ListNode(l1->val);
				ans->next = tmp;
				l1 = l1->next;
			}
			else {
				ListNode *tmp = new ListNode(l2->val);
				ans->next = tmp;
				l2 = l2->next;
			}
			ans = ans->next;
		}
		if (l1)  ans->next = l1;
		if (l2)  ans->next = l2;
		return h->next;;
	}
};
