# Day 010: Arrays #4

## [Tuple with Same Product](https://leetcode.com/problems/tuple-with-same-product/)
```cpp=
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> prodFreq;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                prodFreq[nums[i] * nums[j]]++;
            }
        }
        
        int amtTuples = 0;
        for (pair<int, int> item : prodFreq) {
            int freqCount = item.second;
            if (freqCount > 1) {
                amtTuples += (freqCount) * (freqCount-1) / 2 * 8; 
            }
        }
        
        return amtTuples;
    }
};
```

### Resolução
* Declaramos um hash_map de frequência para produtos de todas as combinações de pares contidas no vector;
* Após a contagem, iteramos pelo hash_map verificando para quais produtos a quantidade de pares (frequência) é maior que 1;
* Caso seja, contabilizamos as possíveis tuples, contando 8 quadras para cada par de combinação (frequência escolhe 2);

### Complexidades
* Espaço: O(n^2)
* Tempo: O(n^2)