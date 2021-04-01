class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1_freq;
        for (int num : nums1) {
            nums1_freq[num]++;
        }
        
        vector<int> intersect;
        for (int num : nums2) {
            if (nums1_freq[num]) {
                intersect.push_back(num);
                nums1_freq[num]--;
            }
        }

        return intersect;
    }
};
