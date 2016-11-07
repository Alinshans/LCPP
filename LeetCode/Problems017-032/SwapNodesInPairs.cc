// Title:  Swap Nodes in Pairs
// Language: C++
// Runtime: 3 ms
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
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)   return head;
		ListNode *p1 = head, *p2 = head->next;
		ListNode *h = new ListNode(0);
		ListNode *pre = h;
		while (p2) {
			ListNode *tmp = p2->next;
			pre->next = p2;
			p2->next = p1;
			p1->next = tmp;
			if (!tmp) break;
			pre = p1;
			p1 = tmp;
			p2 = p1->next;
		}
		return h->next;
	}
};
