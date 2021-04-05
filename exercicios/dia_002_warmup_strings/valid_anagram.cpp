class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		
		unordered_map<char, int> sCharsFreq;
		for (int i = 0; i < s.size(); i++) sCharsFreq[s[i]]++;
		
		for (int i = 0; i < t.size(); i++) sCharsFreq[t[i]]--;
		
		for (pair<char, int> el : sCharsFreq) {
			if (el.second != 0) return false;
		}
		
		return true;
	}
};