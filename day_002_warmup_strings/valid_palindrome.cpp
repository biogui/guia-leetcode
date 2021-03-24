class Solution {
public:
    bool isPalindrome(string s) {
        for (char &character : s) {
            character = tolower(character);
        }
        
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (!isalnum(s[start]) && isalnum(s[end])) {
                start++;
            } else if (isalnum(s[start]) && !isalnum(s[end])) {
                end--;
            } else if (!isalnum(s[start]) && !isalnum(s[end])) {
                start++; end--;
            } else {
                if (s[start] != s[end]) return false;
                start++;
                end--;
            }
        }     
        
        return true;
    }
};
