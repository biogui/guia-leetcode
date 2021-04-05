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