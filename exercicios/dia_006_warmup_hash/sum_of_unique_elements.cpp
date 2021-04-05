class Solution {
public:
	int sumOfUnique(vector<int>& nums) {
		unordered_map<int, int> numsFreq;
		for (int num : nums) numsFreq[num]++;
		
		int uniqueSum = 0;
		for (int num : nums) {
			if (numsFreq[num] == 1) uniqueSum += num;
		}
		
		return uniqueSum;
	}
};