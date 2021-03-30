# Day 010: Arrays #4

## [Tuple with Same Product](https://leetcode.com/problems/tuple-with-same-product/)
```cpp=
class Solution {
public:   
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> prod_freq;
        
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                prod_freq[nums[i] * nums[j]]++;
            }
        }
        
        int ans = 0, freq_count = 0;
        for (pair<int, int> item : prod_freq) {
            freq_count = item.second;
            if (freq_count > 1) {
                ans += (freq_count) * (freq_count-1) / 2 * 8; 
            }
        }
    
        return ans;
    }
};
```

### Resolução
* Declaramos um hash_map de frequência dos produtos de todas as combinações de pares contidas no vector;
* Após a contagem, iteramos pelo hash_map verificando para quais produtos a quantidade de pares (frequência) é maior que 1;
* Caso seja, contabilizamos as possíveis tuples, contando 8 quadras para cada par de combinação (frequência escolhe 2);
    
### Complexidades
* Espaço: O(n)
* Tempo: O(n^2)
