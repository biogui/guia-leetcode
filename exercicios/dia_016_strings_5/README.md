# Day 16: Strings #5

## [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
```cpp=
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagramsMap;

        for (string str : strs) {
            vector<int> charFreq(26);
            for (int i = 0; i < str.size(); i++) {
                charFreq[str[i] - 'a']++;
            }
            anagramsMap[charFreq].push_back(str);
        }

        vector<vector<string>> anagramsGroup;
        for (auto group : anagramsMap) {
            anagramsGroup.push_back(group.second);
        }

        return anagramsGroup;
    }
};
```

### Resolução
* Itera-se por todas as strings, criando um array que conta a frequência de caracteres a cada iteração;
* Usa-se tal array como key no map que agrupa os anagramas (declarado inicialmente), adicionando os anagramas em suas devidos grupos;
* Após tal agrupamento, converte-se o map para uma matriz de strings, retornando essa.

### Complexidades
* Espaço: O(n\*m)
* Tempo: O(n\*m)