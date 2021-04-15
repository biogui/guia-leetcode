/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;

		ListNode* head;
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		while (cur1 != NULL && cur2 != NULL) {
			cur1 = cur1->next;
			cur2 = cur2->next;

			if (cur1 == NULL) head = l2;
			else if (cur2 == NULL) head = l1;
		}

		cur1 = l1;
		cur2 = l2;
		int carry = 0;

		ListNode* cur = head;
		ListNode* prev = NULL;
		while (cur1 != NULL || cur2 != NULL) {
			int sum = carry;
			sum += cur1 ? cur1->val : 0;
			sum += cur2 ? cur2->val : 0;

			cur->val = sum % 10;
			carry = sum / 10;

			prev = cur;
			cur = cur->next;
			if (cur1) cur1 = cur1->next;
			if (cur2) cur2 = cur2->next;
		}

		if (carry != 0) {
			ListNode* new_node = new ListNode;

			prev->next = new_node;
			new_node->val = carry;
		}

		return head;
	}
};