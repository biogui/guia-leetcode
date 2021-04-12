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
	const int MAX = 10e5;

	bool hasCycle(ListNode *head) {
		ListNode *cur = head;

		while (cur != NULL) {
			if (cur->val == MAX + 1) {
				return true;
			}

			cur->val = MAX + 1;
			cur = cur->next;
		}

		return false;
	}
};