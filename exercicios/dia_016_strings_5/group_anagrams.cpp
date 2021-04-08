class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<vector<int>, vector<string>> anagramsMap;

		for (string str : strs) {
			vector<int> charFreq(26);
			for (int i = 0; i < str.size(); i++) {
				charFreq[str[i] - 'a']++;
			}
			anagramsMap[charFreq].push_back(str);
		}

		vector<vector<string>> anagramsGroup;
		for (auto group : anagramsMap) {
			anagramsGroup.push_back(group.second);
		}

		return anagramsGroup;
	}
};