from typing import Tuple

class Solution:
    def expand_around_center(self, s: str, left: int, right: int) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left  -= 1
            right += 1
        
        return s[left + 1:right]
        
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 1: return s
            
        max_len = 0
        longest_palindrome = ""
        for i in range(len(s)):
            odd_s  = self.expand_around_center(s, i, i)
            even_s = self.expand_around_center(s, i, i + 1)
            
            max_s = odd_s if len(odd_s) > len(even_s) else even_s
            if len(max_s) > max_len:
                longest_palindrome = max_s
                max_len = len(max_s)
                
        return longest_palindrome