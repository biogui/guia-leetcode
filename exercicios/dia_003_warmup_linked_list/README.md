# Day 003: Warm up - Linked List

## [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};
```

### Resolução
* Usa-se três ponteiros para referenciar três nós consecutivos;
* Inicialmente setamos o ponteiro next para o sucessor do nó do meio (cur);
* O cur aponta para o seu antecessor (prev);
* No fim da iteração andamos com os duas primeiras referências (prev e cur);
* Repete-se até que cur seja nulo.

### Complexidades
* Espaço: O(n)
* Tempo: O(1)

---

## [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow = reverseList(slow);
        while (slow != NULL) {
            if (slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
};
```

### Resolução
* Temos um ponteiro que percorre o array de forma lenta e outro de forma rápida ("Floyd's tortoise and hare"), dessa forma encontramos o meio do vetor (slow);
* Revertemos a segunda metade da lista;
* Após isso, iteramos com dois ponteiros, um a partir do começo do array e do meio revertido, verificando se os valores são diferentes;
* Caso sejam, retornamos "false";
* Se nenhum valor diferir, é retornado "true" após o loop;

### Complexidades
* Espaço: O(1)
* Tempo: O(n)