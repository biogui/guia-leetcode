class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) return "1";

		string prevSaid = countAndSay(n - 1);

		string said;

		int amtCurNum = 1;
		char curNum = prevSaid[0];
		for (int i = 0; i < prevSaid.size(); i++) {
			if (i != prevSaid.size() - 1 && prevSaid[i] == prevSaid[i + 1]) {
				amtCurNum++;
			}
			else {
				said += to_string(amtCurNum) + curNum;
				amtCurNum = 1;
				curNum = prevSaid[i + 1];
			}
		}

		return said;
	}
};