class Solution {
public:   
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> prod_freq;
        
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                prod_freq[nums[i] * nums[j]]++;
            }
        }
        
        int ans = 0, freq_count = 0;
        for (pair<int, int> item : prod_freq) {
            freq_count = item.second;
            if (freq_count > 1) {
                ans += (freq_count) * (freq_count-1) / 2 * 8; 
            }
        }
    
        return ans;
    }
};
