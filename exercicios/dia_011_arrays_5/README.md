# Day 011: Arrays #5

## [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/)
```cpp=
class Solution {
	public:
		bool increasingTriplet(vector<int>& nums) {
			if (nums.size() < 3) return false;

			long long lower_min = 0xffffffff;
			long long bigger_min = 0xffffffff;

			for (int num : nums) {
				if (num <= lower_min) lower_min = num;
				else if (num <= bigger_min) bigger_min = num;
				else return true;

			}

			return false;

		}

};
`````

### Resolução
* Declaramos duas váriaveis, inicializando-as com todos os 32 bits menos  setados de um long long (garantindo que esses sejam maiores que qualquer int);
* Itera-se pelo array verificando se o número atual é menor que um dos dois mínimos do subarray à sua esquerda (lower_min e bigger_min);
* Caso o valor atual seja menor que lower_min, atualiza-se lower_min, caso contrário e se o valor atual for menor que bigger_min, atualiza-se bigger_min;
* Ordem que garante que lower_min < bigger_min seja sempre verdade;
* Caso não haja atualização (atual > bigger_min), retornamos 'true', dado que obtemos uma triplet válida.
    
	### Complexidades
	* Espaço: O(1)
	* Tempo: O(n)
````
