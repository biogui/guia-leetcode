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
	stack<ListNode*> listToStack(ListNode* head){
		stack<ListNode*> stackList;

		ListNode* cur = head;
		while (cur) {
			stackList.push(cur);
			cur = cur->next;
		}

		return stackList;
	}

	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		stack<ListNode*> stackListA = listToStack(headA);
		stack<ListNode*> stackListB = listToStack(headB);

		ListNode* cur = NULL;
		while (!stackListA.empty() && !stackListB.empty()) {
			if (stackListA.top() != stackListB.top()) break;

			cur = stackListA.top();
			stackListA.pop();
			stackListB.pop();
		}

		return cur;
	}
};