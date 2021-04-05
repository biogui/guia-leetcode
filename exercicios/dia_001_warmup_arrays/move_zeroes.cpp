class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() < 2) return;
		
		int leftZero = 0, cur = 0;
		while(cur < nums.size()) {
			if (nums[cur] != 0) {
				swap(nums[leftZero], nums[cur]);
				leftZero++;
			}
			cur++;
		}
	}
};