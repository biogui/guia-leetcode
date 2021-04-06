# Day 14: Strings #3

## [Find Kth Bit in Nth Binary String](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/)
```cpp=
class Solution {
public:
    char invert(const char& c) {
        return c == '0' ? '1' : '0';
    }

    char findKthBitAux(int n, int k, int strLenN) {
        if (n == 1) return '0';

        int strLenPrevN = (strLenN + 1) / 2;
        if (k == strLenPrevN) {
            return '1';
        }
        else if (k < strLenPrevN) {
            return findKthBitAux(n - 1, k, strLenPrevN - 1);
        }
        else {
            return invert(findKthBitAux(n - 1, strLenN - k + 1, strLenPrevN - 1));
        }
    }

    char findKthBit(int n, int k) {
        return findKthBitAux(n, k, pow(2, n) - 1);
    }
};
```

### Resolução
* Na função recursiva, é verificado se k é igual a posição central (equivalente ao tamanho da string S_n-1) da string S_n, retornando '1' caso verdadeiro;
* Caso contrário, verifica-se em qual metade da string S_n k está;
* Quando k é menor que a posição central de S_n, retornamos o k-ésimo caracter da substring da metade esquerda de S_n (equivalente a string S_n-1);
* Quando k é maior que a posição central de S_n, retornamos k-ésimo caracter invertido da substring da metade direita de S_n (equivalente a string S_n-1 revertida);
* A string S_n-1 revertida é obtida através distância de k em relação ao final de S_n (strLenN - k + 1).

### Complexidades
* Espaço: O(n)
* Tempo: O(lg(n))