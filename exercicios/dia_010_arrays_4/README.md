# Day 010: Arrays #4

## [Tuple with Same Product](https://leetcode.com/problems/tuple-with-same-product/)
```cpp=
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> prod_freq;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                prod_freq[nums[i] * nums[j]]++;
            }
        }
        
        int amt_tuples = 0, freq_count = 0;
        for (pair<int, int> item : prod_freq) {
            freq_count = item.second;
            if (freq_count > 1) {
                amt_tuples += (freq_count) * (freq_count-1) / 2 * 8; 
            }
        }
        
        return amt_tuples;
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