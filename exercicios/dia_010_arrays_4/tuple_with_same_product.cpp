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