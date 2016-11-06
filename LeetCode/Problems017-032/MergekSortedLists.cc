// Title:  Merge k Sorted Lists
// Language: C++
// Runtime: 39 ms
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *ans = new ListNode(0);
		ListNode *h = ans;
		multiset<int> ret;
		for (int i = 0; i < lists.size(); ++i) {
			ListNode* tmp = lists[i];
			while (tmp) {
				ret.insert(tmp->val);
				tmp = tmp->next;
			}
		}
		for (auto it = ret.begin(); it != ret.end(); ++it) {
			ListNode *tmp = new ListNode(*it);
			ans->next = tmp;
			ans = ans->next;
		}
		return h->next;
	}
};
