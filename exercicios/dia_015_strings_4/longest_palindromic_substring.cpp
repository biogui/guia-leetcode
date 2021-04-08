class Solution {
public:
	int expandFromCenter(string s, int l, int r) {
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			l--; r++;
		}

		return r - l - 1;
	}

	string longestPalindrome(string s) {
		if (s.size() < 1) return "";

		int start = 0, end = 0, maxLen = 0;
		for (int i = 0; i < s.size(); i++) {
			int oddLen = expandFromCenter(s, i, i);
			int evenLen = expandFromCenter(s, i, i + 1);
			
			int len = max(oddLen, evenLen);
			if (len > maxLen) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
				maxLen = len;
			}
		}

		return s.substr(start, maxLen);
	}
};