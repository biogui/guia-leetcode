# Day 002: Warm Up - Strings

## [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
```cpp=
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashmap;
        
        if (s.size() != t.size()) return false;
        
        for (int i = 0; i < s.size(); i++) {
            hashmap[s[i]]++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            hashmap[t[i]]--;
        }
        
        for (pair<char, int> el : hashmap) {
            if (el.second != 0) return false;
        }
        
        return true;     
    }
};

```

### Resolução
* Hashmap de frequência das letras da primeira string;
* Itera-se pela segunda string realizando um decremento da frequência de cada key caso ela esteja presente;
* Por fim, é verificado se todos os values(frequências) do hashmap estão zerados. Caso contrario, é retornado false.
    
### Complexidades
* Tempo: O(n)
* Espaço: O(1)

## [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
```cpp=
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        bool is_valid = false;
        while (start < end) {
            is_valid = (isalnum(s[start]) && isalnum(s[end]));
            
            if (is_valid && tolower(s[start]) != tolower(s[end])) return false;
            
            start += (is_valid) + (!isalnum(s[start]));
            end -= (is_valid) + (!isalnum(s[end]));
        }     

        return true;
    }
        
};
```

### Resolução
* Itera-se pela string com dois ponteiros (começo e final), um incrementando e outro decrementando, respectivamente;
* É verificado se os caracteres para os quais os ponteiros apontam são iguais, ignorando caracteres não alfanuméricos via uma variável booleana de verificação, caso não sejam é retornado falso.

### Complexidades
* Espaço: O(n)
* Tempo: O(1)
