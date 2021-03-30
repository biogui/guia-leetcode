# Day 006: Warm up - Hash

## [Sum of Unique Elements](https://leetcode.com/problems/sum-of-unique-elements/)
```cpp=
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> nums_freq;
        for (int num : nums) {
            nums_freq[num]++;
        }
        
        int unique_sum = 0;
        for (int num : nums) {
            if (nums_freq[num] == 1) unique_sum += num;
        }
        
        return unique_sum;
    }
};
```

### Resolução
* Criamos um hash_map de frequência a partir do vetor inicial; 
* Iteramos pelo hash_map, acrescentando na soma os valores únicos;
    
### Complexidades
* Espaço: O(n)
* Tempo: O(n)

---

## [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/)
```cpp=
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> arr_set;
        for (int num : arr) {   
            arr_set.insert(num);
        }
    
        for (int i = 1; i <= 2000; i++) {
            if (arr_set.find(i) == arr_set.end()) k--;
            if (k == 0) return i;
        }
        
        return -1;
    }
};
```

### Resolução
* Criamos um hash_set a partir do vetor inicial
* Como os números presentes no array e o 'k' são menores ou iguais a 1000, o k-ésimo número perdido, no pior caso, é 2000;
* Assim, iteramos de 1 até 2000, e caso o número não esteja presente no set decrementamos o k;
* Se 'k' zera, saimos do loop, retornando o k-ésimo número perdido; 

### Complexidades
* Espaço: O(n)
* Tempo: O(n)
