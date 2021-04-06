class Solution {
public:
	char invert(const char& c) {
		return c == '0' ? '1' : '0';
	}

	char findKthBitAux(int n, int k, int strLenN) {
		if (n == 1) return '0';

		int strLenPrevN = (strLenN + 1) / 2;
		if (k == strLenPrevN) {
			return '1';
		}
		else if (k < strLenPrevN) {
			return findKthBitAux(n - 1, k, strLenPrevN - 1);
		}
		else {
			return invert(findKthBitAux(n - 1, strLenN - k + 1, strLenPrevN - 1));
		}
	}

	char findKthBit(int n, int k) {
		return findKthBitAux(n, k, pow(2, n) - 1);
	}
};