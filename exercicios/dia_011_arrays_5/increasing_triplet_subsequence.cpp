class Solution {
	public:
		bool increasingTriplet(vector<int>& nums) {
			if (nums.size() < 3) return false;
			
			long long lowerMin = 0xffffffff;
			long long biggerMin = 0xffffffff;
			for (int num : nums) {
				if (num <= lowerMin) lowerMin = num;
				else if (num <= biggerMin) biggerMin = num;
				else return true;
			}
			
			return false;
		}
};