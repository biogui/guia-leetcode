/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		
		vector<vector<int>> tree_by_level;
		
		queue<TreeNode *> next_nodes;
		next_nodes.push(root);
		
		while (!next_nodes.empty()) {
			vector<int> nodes;
			int size = next_nodes.size();
			
			for (int i = 0; i < size; i++) {
				TreeNode *cur = next_nodes.front();
				nodes.push_back(cur->val);
				next_nodes.pop();
				
				if (cur->left) next_nodes.push(cur->left);
				if (cur->right) next_nodes.push(cur->right);
			}
			
			tree_by_level.push_back(nodes);
		}
		
		return tree_by_level;
	}
};