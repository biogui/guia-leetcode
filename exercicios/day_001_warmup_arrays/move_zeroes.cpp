class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        
        int left_zero = 0, curr = 0;
        while(curr < nums.size()) {
            if (nums[curr] != 0) {
                swap(nums[left_zero], nums[curr]);
                left_zero++;
            }
            curr++;
        }
    }
};
