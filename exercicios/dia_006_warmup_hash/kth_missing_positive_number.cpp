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