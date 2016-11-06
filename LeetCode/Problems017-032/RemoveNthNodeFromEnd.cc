// Title:  Remove Nth Node From End of List
// Language: C++
// Runtime: 0 ms
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head || !n) return head;
		ListNode *pre = head, *cur = head;
		for (int i = 0; i<n; ++i)
			cur = cur->next;
		if (!cur)    return head->next;
		while (cur->next) {
			pre = pre->next;
			cur = cur->next;
		}
		pre->next = pre->next->next;
		return head;
	}
};
