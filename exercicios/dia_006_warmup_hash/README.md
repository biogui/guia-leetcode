# Day 006: Warm up - Hash

## [Sum of Unique Elements](https://leetcode.com/problems/sum-of-unique-elements/)
```cpp=
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> numsFreq;
        for (int num : nums) numsFreq[num]++;
        
        int uniqueSum = 0;
        for (int num : nums) {
            if (numsFreq[num] == 1) uniqueSum += num;
        }
        
        return uniqueSum;
    }
};
```

### Resolução
* Criamos um hash_map de frequência a partir do vetor inicial;
* Iteramos pelo hash_map, incrementando na soma os valores únicos.

### Complexidades
* Espaço: O(n)
* Tempo: O(n)

---

## [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/)
```cpp=
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> arrSet;
        for (int num : arr) arrSet.insert(num);
        
        for (int i = 1; i <= 2000; i++) {
            if (arrSet.find(i) == arrSet.end()) k--;
            if (k == 0) return i;
        }
        
        return -1;
    }
};
```

### Resolução
* Criamos um hash_set a partir do vetor inicial;
* Como os números presentes no array e o 'k' são menores ou iguais a 1000, o k-ésimo número perdido, no pior caso, é 2000;
* Assim, iteramos de 1 até 2000, e caso o número não esteja presente no set decrementamos o k;
* Se 'k' zera, saimos do loop, retornando o k-ésimo número perdido.

### Complexidades
* Espaço: O(n)
* Tempo: O(n)
