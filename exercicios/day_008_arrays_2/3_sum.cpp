class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int low = i + 1, high = len - 1;
                while (low < high) {
                    int sum = -nums[i];
                    if (nums[low] + nums[high] == sum) {
                        ans.push_back({nums[i], nums[low], nums[high]});
                        
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (high > low && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    } else if (nums[low] + nums[high] > sum) {
                        high--;
                    } else {
                        low++;
                    }
                }
            } 
        }
        
        return ans;
    }
};
