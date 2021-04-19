# Day 19: Linked List #3

## [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
    }
};
```

### Resolução
* Utiliza-se dois ponteiros, um percorrendo os índices ímpares e outro os pares;
* Em um loop, itera-se pela lista alterando a lista com auxílio dos ponteiros ímpar e par;
* A cada iteração um nó de índice ímpar é remanejado para o começo da lista, assim como um nó de índice par para o final;
* Ao sair do loop, pós o termino da lista, uni-se o final da lista dos índice ímpares com o primeiro nó de índice par, guardado anteriormente (evenHead);
* Por fim, retornamos a lista alterada.

### Complexidades
* Espaço: O(1)
* Tempo: O(n)