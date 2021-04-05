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