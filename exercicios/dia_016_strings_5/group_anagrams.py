from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = defaultdict(list)
        for string in strs:
            char_freq = [0]*26
            for c in string:
                char_freq[ord(c)-ord('a')] += 1
            string_freq = '|'.join([str(freq) for freq in char_freq])
            hashmap[string_freq].append(string)
        
        return hashmap.values()