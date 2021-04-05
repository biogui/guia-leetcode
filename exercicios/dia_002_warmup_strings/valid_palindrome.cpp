class Solution {
public:
	bool isPalindrome(string s) {
		int start = 0, end = s.size() - 1;
		while (start < end) {
			bool areValidsChars = (isalnum(s[start]) && isalnum(s[end]));
			
			if (areValidsChars && tolower(s[start]) != tolower(s[end])) {
				return false;
			}
			
			start += (areValidsChars) + (!isalnum(s[start]));
			end -= (areValidsChars) + (!isalnum(s[end]));
		}
		
		return true;
	}
};