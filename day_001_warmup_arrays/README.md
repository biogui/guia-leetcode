# Day 001: Warm Up - Arrays

## [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

```cpp=
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for (int num : nums1) {
            hashmap[num]++;
        }
        
        vector<int> ans;        
        for (int num : nums2) {
            if (hashmap[num]) {
                ans.push_back(num);
                hashmap[num]--;
            }
        }
        return ans;
    }
};
```

### Resolução
* Cria-se um hashmap de frequência cujas chaves são os números do primeiro array e os valores são as frequências dos próprios números;
* Itera-se no segundo array e é verificado se a chave já existe no  hashmap. Caso exista, o valor é adicionado ao array de resposta e a frequência é decrementada no hashmap criado inicialmente. 
    
### Complexidades
* Espaço: O(max(n,m))
* Tempo: O(max(n,m))

## [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
```cpp=
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        
        int left_zero = 0, curr = 0;  
        while(curr < nums.size()) {
            if (nums[curr] != 0) {
                swap(nums[left_zero], nums[curr]);
                left_zero++;
            }
            curr++;
        }
    }
};
```

### Resolução
- Abordagem de dois ponteiros;
- Os dois ponteiros são iniciados no começo do array e percorrem juntos até que cheguem a um 0 (realizando fake swaps da mesma posição para a mesma posição). A partir daí o ponteiro left_zero marcará a posição do zero mais a esquerda;
- Em seguida, o ponteiro curr itera pelo array até o primeiro valor não-nulo depois do left_zero, realizando o swap quando o encontra.

### Complexidades
* Espaço: O(n)
* Tempo: O(1)
