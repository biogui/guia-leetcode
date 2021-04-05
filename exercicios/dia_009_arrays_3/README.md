x# Day 009: Arrays #3

## [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

### Solução 1
```cpp=
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> columns;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
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
* Itarando novamente pela matrix, verifica-se, para cada elemento, se alguma das suas coordenadas está contida em algum dos sets iniciais;
* Caso sim, o elemento é trocado para 0.

### Complexidades
* Espaço: O(n + m)
* Tempo: O(n\*m)

---

### Solução 2
```cpp=
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isThereZeroInFirstCol = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) isThereZeroInFirstCol = true;
            
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        if (matrix[0][0] == 0) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (isThereZeroInFirstCol) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
```

### Resolução
* Usamos a primeira linha e a primeira coluna como hashset para verificar a existência de 0s na matriz;
* A primeira linha guarda quais colunas possuem 0s;
* A primeira coluna guarda quais linhas possuem 0s;
* Para criá-lo iteramos por toda a matrix, caso um 0 seja encontrado:
    * O primeiro elemento da linha (na primeira coluna) é setado pra 0;
    * O primeiro elemento da coluna (na primeira linha) é setado pra 0;
* Após essa operação, iteramos pela sub-matriz advinda da matriz sem a primeira linha e coluna (indo de \[1][1] até \[n-1][n-1]);
* Para cada elemento desta iteração verificamos se a primeira linha ou coluna respectivas ao elemento estão setadas para 0, caso sim, o elemento atual é setado para zero;
* Após a iteração nessa sub-matriz, verificamos se a primeira coluna e a linha devem ser preenchidas com 0s;
* Por fim, temos a matrix com as devidas linhas e colunas preenchidas.

### Complexidades
* Espaço: O(1)
* Tempo: O(n\*m)