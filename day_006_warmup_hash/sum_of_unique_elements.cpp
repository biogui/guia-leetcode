class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> nums_freq;
        for (int num : nums) {
            nums_freq[num]++;
        }
        
        int unique_sum = 0;
        for (int num : nums) {
            if (nums_freq[num] == 1) unique_sum += num;
        }
        
        return unique_sum;
    }
};
