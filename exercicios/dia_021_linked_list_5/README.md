# Day 21: Linked List #5

## [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

### Solução
```cpp=
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
```

### Resolução
* Itera-se pela lista até o k-ésimo nó, guardando esse em "node1" após a saída do loop;
* Em seguida, itera-se com dois ponteiros, o primeiro (node2) partindo do ínicio e o segundo do k-ésimo;
* Dessa forma, quando o segundo chega ao último nó da lista, temos o node2 na k-ésima posição a partir do final;
* Por fim, é realizado o swap dos valores de "node1" e "node2", retornando a lista alterada.

### Complexidades
* Espaço: O(1)
* Tempo: O(n)