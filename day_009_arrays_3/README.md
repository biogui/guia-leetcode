# Day 009: Arrays #3

## [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

### Solução 1
```cpp=
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> columns;
        
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rows.find(i) != rows.end() || columns.find(j) != columns.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
```

### Resolução
* Declara-se dois sets, um para armazenar as linhas que devem ser zeradas e outro para armazenar as colunas que devem ser zeradas;
* Itera-se pela matrix original a procura de zeros, caso algum seja encontrado, adicionamos sua linha e coluna aos sets iniciais;
* Itarando novamente pela matrix, verifica-se, para cada elemento, se alguma das suas coordenadas está contida em algum dos sets iniciais, caso sim, o elemento é trocado para 0.

    
### Complexidades
* Espaço: O(n + m)
* Tempo: O(n*m)

---

### Solução 2
```cpp=
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool isFirstCol = false;
        
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) isFirstCol = true;
            
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
                
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (isFirstCol) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }     
    }
};
```

### Resolução
https://leetcode.com/problems/set-matrix-zeroes/solution/
    
### Complexidades
* Espaço: O(1)
* Tempo: O(n*m)
