# Day 012: Strings #1

## [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
```cpp=
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        int minSize = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < minSize) {
                minSize = strs[i].size();
            }
        }

        for (int i = 0; i < minSize; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0].substr(0, minSize);
    }
};

```

### Resolução
* Inicialmente iteramos por todas as strings buscando o tamanho da menor string;
* Iteramos por todos índices até o índice máximo da menor string, conferindo se em todas as outras strings o char no índice atual é igual;
* Caso o índice confira para alguma string, é retornada a substring a esquerda daquele índice como maior prefixo possível;
* Caso todas strings contenham a menor string, essa é retornada após o fim dos loops.

### Complexidades
* Espaço: O(1)
* Tempo: O(n\*m)