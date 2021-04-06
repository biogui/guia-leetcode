class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";

		int minSize = INT_MAX;
		for (int i = 0; i < strs.size(); i++) {
			if (strs[i].size() < minSize) {
				minSize = strs[i].size();
			}
		}

		for (int i = 0; i < minSize; i++) {
			for (int j = 1; j < strs.size(); j++) {
				if (strs[0][i] != strs[j][i]) {
					return strs[0].substr(0, i);
				}
			}
		}

		return strs[0].substr(0, minSize);
	}
};
