class Solution {
public:

    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        bool is_valid = false;
        while (start < end) {
            is_valid = (isalnum(s[start]) && isalnum(s[end]));
            
            if (is_valid && tolower(s[start]) != tolower(s[end])) return false;
            
            start += (is_valid) + (!isalnum(s[start]));
            end -= (is_valid) + (!isalnum(s[end]));
        }     
        
        return true;
    }
};
