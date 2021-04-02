class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() < 2) return;
		
		int left_zero = 0, cur = 0;
		while(cur < nums.size()) {
			if (nums[cur] != 0) {
				swap(nums[left_zero], nums[cur]);
				left_zero++;
			}
			cur++;
		}
	}
};