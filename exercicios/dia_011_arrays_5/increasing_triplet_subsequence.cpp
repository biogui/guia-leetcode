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