class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashmap;
        
        if (s.size() != t.size()) {
            return false;
        }
        
        for (int i = 0; i < s.size(); i++) {
            hashmap[s[i]]++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            hashmap[t[i]]--;
        }
        
        for (pair<char, int> el : hashmap) {
            if (el.second != 0) {
                return false;
            }
        }
        
        return true;     
    }
};
