class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix[0].size();
		for (int i = 0; i < n / 2 + n % 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				// guardando superior-direito
				int temp = matrix[j][n-1-i];
				
				// superior-esquerdo para superior-direito
				matrix[j][n-1-i] = matrix[i][j]; 
				// inferior-esquerdo para superior-esquerdo
				matrix[i][j] = matrix[n-1-j][i];
				// inferior-direito para inferior-esquerdo
				matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
				// superior-direito para inferior-direito
				matrix[n-1-i][n-1-j] = temp;
			}
		}
	}
};