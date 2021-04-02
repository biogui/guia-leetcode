class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		
		unordered_map<char, int> s_chars_freq;
		for (int i = 0; i < s.size(); i++) s_chars_freq[s[i]]++;
		
		for (int i = 0; i < t.size(); i++) s_chars_freq[t[i]]--;
		
		for (pair<char, int> el : s_chars_freq) {
			if (el.second != 0) return false;
		}
		
		return true;
	}
};