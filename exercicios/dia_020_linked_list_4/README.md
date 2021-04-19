# Day 20: Linked List #4

## [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

### Solução
```cpp=
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
```

### Resolução
* Primeiramente cria-se duas pilhas a partir das duas listas;
* Em seguida desempilha-se concomitantemente ambas as pilhas comparando os nós um a um;
* Ou seja, "itera-se nas listas" do fim ao início até os nós diferirem;
* Assim, saindo do loop, retorna-se o último nó comum.

### Complexidades
* Espaço: O(n + m)
* Tempo: O(max(n, m))