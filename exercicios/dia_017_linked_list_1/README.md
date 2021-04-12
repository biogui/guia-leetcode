# Day 17: Linked List #1

## [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

### Solução 1
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
```

### Resolução
* Itera-se por toda a lista, setando os valores já visitados para um valor não presente na lista (maior que o máximo);
* Caso seja encontrado algum nó já setado para o valor excedente ao máximo, retorna-se "true", pois isso confirma um ciclo;
* Caso a lista seja iterada até um nó nulo, retorna-se "false", já que não existe um ciclo na lista.

### Complexidades
* Espaço: O(1)
* Tempo: O(n)

---

### Solução 2
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;

        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};
```

### Resolução
* Têm-se dois ponteiros, um que itera de forma rápida e outro de forma lenta ("Floyd's tortoise and hare");
* Caso esses ponteiros apontem para o mesmo nó em algum momento, retorna-se "true" ao sair do loop;
* Caso a lista seja iterada até um nó nulo, retorna-se "false", já que não existe um ciclo na lista.

### Complexidades
* Espaço: O(1)
* Tempo: O(n)