// Title:  Reverse Nodes in k-Group
// Language: C++
// Runtime: 23 ms
// Submitted: 2016/11/7

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
	ListNode* reverse(ListNode *first, ListNode *last) {
		ListNode *cur = first->next;
		ListNode *next = cur->next;
		while (next != last) {
			cur->next = next->next;
			next->next = first->next;
			first->next = next;
			next = cur->next;
		}
		return cur;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k < 2)  return head;
		ListNode *h = new ListNode(0);
		h->next = head;
		ListNode *pre = h;
		int i = 0;
		while (head != NULL) {
			++i;
			if (i % k == 0) {
				pre = reverse(pre, head->next);
				head = pre->next;
				continue;
			}
			head = head->next;
		}
		return h->next;
	}
};
