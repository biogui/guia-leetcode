# Day 002: Warm Up - Strings

## [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
```cpp=
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> sCharsFreq;
        for (int i = 0; i < s.size(); i++) sCharsFreq[s[i]]++;
        
        for (int i = 0; i < t.size(); i++) sCharsFreq[t[i]]--;
        
        for (pair<char, int> el : sCharsFreq) {
            if (el.second != 0) return false;
        }
        
        return true;
    }
};
```

### Resolução
* Hashmap de frequência das letras da primeira string;
* Itera-se pela segunda string realizando um decremento da frequência de cada key caso ela esteja presente;
* Por fim, é verificado se todos os values(frequências) do hashmap estão zerados;
* Caso contrario, é retornado "false";
* Se todos values forem nulos, é retornado "true" após o loop.

### Complexidades
* Tempo: O(n)
* Espaço: O(1)

---

## [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
```cpp=
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            bool areValidsChars = (isalnum(s[start]) && isalnum(s[end]));
            
            if (areValidsChars && tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            
            start += (areValidsChars) + (!isalnum(s[start]));
            end -= (areValidsChars) + (!isalnum(s[end]));
        }
        
        return true;
    }
};
```

### Resolução
* Itera-se pela string com dois ponteiros (começo e final), um incrementando e outro decrementando, respectivamente;
* É verificado se os caracteres para os quais os ponteiros apontam são iguais, ignorando caracteres não alfanuméricos via uma variável booleana de verificação;
* Caso os respectivos chars sejam diferentes é retornado "false";
* Se nenhum char diferir, é retornado "true" após o loop.

### Complexidades
* Espaço: O(n)
* Tempo: O(1)