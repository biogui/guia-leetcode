# Day 008: Arrays #2

## [3sum](https://leetcode.com/problems/3sum/)
```cpp=
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int low = i + 1, high = len - 1;
                while (low < high) {
                    int sum = -nums[i];
                    if (nums[low] + nums[high] == sum) {
                        ans.push_back({nums[i], nums[low], nums[high]});
                        
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (high > low && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    } else if (nums[low] + nums[high] > sum) {
                        high--;
                    } else {
                        low++;
                    }
                }
            } 
        }
        
        return ans;
    }
};
```

### Resolução
* Ordena-se o array original;
* Itera-se até o penultimo valor do array, pois, inicialmente, escolhemos apenas o primeiro valor da tripla;
* Com a abordagem de dois ponteiros, procuramos a dupla que complementa o primeiro valor escolhido, evitando repetições de triplas (pulando iterações para valores iniciais de triplas já testados);
* Caso a soma do par (high, low) seja maior que o complemento, diminuimos essa soma decrementando o high;
* Caso contrario, analogamente, incrementamos o low.
    
### Complexidades
* Espaço: O(n)
* Tempo: O(n^2)
