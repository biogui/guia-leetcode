class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return {};
		
		sort(nums.begin(), nums.end());
		
		vector<vector<int>> valids3Sums;
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
				int low = i + 1, high = nums.size() - 1;
				while (low < high) {
					int complement = -nums[i];
					int cur_sum = nums[low] + nums[high];
					
					if (cur_sum == complement) {
						valids3Sums.push_back({nums[i], nums[low], nums[high]});
						
						while (low < high && nums[low] == nums[low + 1]) low++;
						while (high > low && nums[high] == nums[high - 1]) high--;
						low++;
						high--;
					} else if (cur_sum > complement) {
						high--;
					} else if (cur_sum < complement) {
						low++;
					}
				}
			}
		}
		
		return valids3Sums;
	}
};