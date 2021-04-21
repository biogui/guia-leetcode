/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	void swapNodesValues(int &a, int &b) {
		int temp = a;
		a = b;
		b = temp;
	}

	ListNode* swapNodes(ListNode* head, int k) {
		ListNode* cur = head;
		for (int i = 1; i < k; i++) {
			cur = cur->next;
		}

		ListNode* node1 = cur;
		ListNode* node2 = head;
		while (cur->next) {
			node2 = node2->next;
			cur = cur->next;
		}
		swapNodesValues(node1->val, node2->val);

		return head;
	}
};