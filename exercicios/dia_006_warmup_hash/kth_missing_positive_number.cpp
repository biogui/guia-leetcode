class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		unordered_set<int> arr_set;
		for (int num : arr) arr_set.insert(num);
		
		for (int i = 1; i <= 2000; i++) {
			if (arr_set.find(i) == arr_set.end()) k--;
			if (k == 0) return i;
		}
		
		return -1;
	}
};