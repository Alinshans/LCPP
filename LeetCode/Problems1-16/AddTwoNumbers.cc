// Title: Add Two Numbers
// Language: C++
// Runtime: 28 ms
// Submitted: 2016/11/2

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ans = new ListNode(0);
		ListNode *cur = ans;
		int carry = 0;
		while (l1 || l2) {
			int tmp = carry;
			if (l1) {
				tmp += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				tmp += l2->val;
				l2 = l2->next;
			}
			carry = tmp / 10;
			cur->val = tmp % 10;
			if (l1 || l2 || carry) {
				ListNode *next = new ListNode(carry);
				cur->next = next;
				cur = cur->next;
			}
		}
		cur->next = NULL;
		return ans;
	}
};
