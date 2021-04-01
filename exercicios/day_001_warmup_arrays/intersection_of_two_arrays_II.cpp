class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for (int num : nums1) {
            hashmap[num]++;
        }
        
        vector<int> ans;
        
        for (int num : nums2) {
            if (hashmap[num]) {
                ans.push_back(num);
                hashmap[num]--;
            }
        }
        return ans;
    }
};
