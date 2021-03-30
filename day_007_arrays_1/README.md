# Day 007: Arrays #1

## [Rotate Image](https://leetcode.com/problems/rotate-image/)
```cpp=
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        for (int i = 0; i < (n / 2) + (n % 2); i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[j][n-1-i];

                // esquerda-cima no direita-cima
                matrix[j][n-1-i] = matrix[i][j]; 
                // esquerda-baixo no esquerda-cima
                matrix[i][j] = matrix[n-1-j][i];
                // direita-baixo no esquerda-baixo
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                // direita-cima no direita-baixo
                matrix[n-1-i][n-1-j] = temp;
            }
        }
    }
};
```

### Resolução
https://leetcode.com/problems/rotate-image/solution/
    
### Complexidades
* Espaço: O(1)
* Tempo: O(n^2)
