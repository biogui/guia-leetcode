# Day 13: Strings #2

## [Count and Say](https://leetcode.com/problems/count-and-say/)
```cpp=
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prevSaid = countAndSay(n - 1);

        string said;

        int amtCurNum = 1;
        char curNum = prevSaid[0];
        for (int i = 0; i < prevSaid.size(); i++) {
            if (i != prevSaid.size() - 1 && prevSaid[i] == prevSaid[i + 1]) {
                amtCurNum++;
            }
            else {
                said += to_string(amtCurNum) + curNum;
                amtCurNum = 1;
                curNum = prevSaid[i + 1];
            }
        }

        return said;
    }
};
```

### Resolução
* Chama-se a função recursivamente até o caso base (n = 1);
* Partindo do retorno do caso base, iteramos por essa string;
* Começando a partir do primeiro caracter, conta-se quantas vezes esse aparece em sequência;
* Caso a sequência seja quebrada, adiciona-se o contador e o respectivo caracter à string de resposta;
* Em seguida, analogamente, realiza-se a mesma contagem para caracter que quebrou a sequência;
* Isso em loop, enquanto a string retornada (prevSaid) não acabar;
* Depois disso, tem-se uma última iteração para adicionar o contador e o caracter da sequência que finaliza a string.

### Complexidades
* Espaço: O(n)
* Tempo: O(n^2)