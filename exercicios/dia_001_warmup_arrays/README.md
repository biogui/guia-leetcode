# Day 001: Warm Up - Arrays

## [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

```cpp=
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1Freq;
        for (int num : nums1) nums1Freq[num]++;
        
        vector<int> intersect;
        for (int num : nums2) {
            if (nums1Freq[num]) {
                intersect.push_back(num);
                nums1Freq[num]--;
            }
        }
        
        return intersect;
    }
};
```

### Resolução
* Cria-se um hashmap de frequência cujas chaves são os números do primeiro array e os valores são as frequências dos próprios números;
* Itera-se no segundo array e é verificado se a chave já existe no hashmap;
* Caso exista, o valor é adicionado ao array de resposta e a frequência é decrementada no hashmap criado inicialmente;
* Ao final retornamos o array completo.

### Complexidades
* Espaço: O(max(n,m))
* Tempo: O(max(n,m))

---

## [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
```cpp=
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        
        int leftZero = 0, cur = 0;
        while(cur < nums.size()) {
            if (nums[cur] != 0) {
                swap(nums[leftZero], nums[cur]);
                leftZero++;
            }
            cur++;
        }
    }
};
```

### Resolução
* Abordagem de dois ponteiros;
* Os dois ponteiros são iniciados no começo do array e percorrem juntos até que cheguem a um 0 (realizando fake swaps em uma mesma posição). A partir daí o ponteiro left_zero marcará a posição do zero mais a esquerda;
* Em seguida, o ponteiro cur itera pelo array até o primeiro valor não-nulo depois do left_zero, realizando o swap quando o encontra;
* Disso, temos por fim todos os 0s "swapados" para a direita do array.

### Complexidades
* Espaço: O(n)
* Tempo: O(1)