# Day 012: Strings #1

## [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
```cpp=
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int amt_strs = strs.size();
        if (amt_strs == 0) return "";
        
        int min_size = INT_MAX;
        for (int i = 0; i < amt_strs; i++) {
            if (strs[i].size() < min_size) {
                min_size = strs[i].size();
            }
        }
        
        for (int i = 0; i < min_size; i++) {
            for (int j = 1; j < amt_strs; j++) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0].substr(0, min_size);
    }
};
`````

### Resolução
* Inicialmente iteramos por todas as strings buscando o tamanho da menor string;
* Iteramos por todos índices até o índice máximo da menor string, conferindo se em todas as outras strings o char no índice atual é igual;
* Caso o índice confira para alguma string, é retornada a substring a esquerda daquele índice como maior prefixo possível;
* Caso todas strings contenham a menor string, essa é retornada após o fim dos loops.

### Complexidades
	* Espaço: O(1)
	* Tempo: O(n*m)

