# Day 15: Strings #4

## [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
```cpp=
class Solution {
public:
    int expandFromCenter(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--; r++;
        }

        return r - l - 1;
    }

    string longestPalindrome(string s) {
        if (s.size() < 1) return "";

        int start = 0, end = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int oddLen = expandFromCenter(s, i, i);
            int evenLen = expandFromCenter(s, i, i + 1);
            
            int len = max(oddLen, evenLen);
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
                maxLen = len;
            }
        }

        return s.substr(start, maxLen);
    }
};
```

### Resolução
* Itera-se por todos os caracteres da string, calculando o tamanho máximo do palíndromo o qual tem como centro aquele caracter;
* Para calcular o tamanho máximo, expandimos para os dois lados a partir do centro verificando nas posições expandidas (l e r) os caracteres são iguais (considera-se centros com 1 ou 2 caracteres — tamanho ímpar e par, respectivamente);
* Após tal operãção, verifica-se se o tamanho máximo obtido ultrapassa o maior tamanho obtido até então, caso sim, atualiza-se os índices de início e fim do palíndromo de resposta;
* Ao final do loop, retornamos a subtring delimitada pelos índices calculados anteriormente.

### Complexidades
* Espaço: O(n) -> s.substr retorna uma cópia da substring
* Tempo: O(n^2)