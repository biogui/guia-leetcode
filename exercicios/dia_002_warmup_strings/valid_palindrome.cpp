class Solution {
public:
	bool isPalindrome(string s) {
		int start = 0, end = s.size() - 1;
		while (start < end) {
			bool are_valids_chars = (isalnum(s[start]) && isalnum(s[end]));
			
			if (are_valids_chars && tolower(s[start]) != tolower(s[end])) {
				return false;
			}
			
			start += (are_valids_chars) + (!isalnum(s[start]));
			end -= (are_valids_chars) + (!isalnum(s[end]));
		}
		
		return true;
	}
};