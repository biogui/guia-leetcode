class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int amt_strs = strs.size();
        if (amt_strs == 0) return "";

        int min_size = INT_MAX;
        for (int i = 0; i < amt_strs; i++) {
            if (strs[i].size() < min_size) {
                min_size = strs[i].size();
            }
        }

        for (int i = 0; i < min_size; i++) {
            for (int j = 1; j < amt_strs; j++) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0].substr(0, min_size);
    }
};
