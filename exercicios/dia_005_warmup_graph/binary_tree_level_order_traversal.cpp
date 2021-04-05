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
		
		vector<vector<int>> treeByLevel;
		
		queue<TreeNode *> nextNodes;
		nextNodes.push(root);
		
		while (!nextNodes.empty()) {
			vector<int> nodes;
			int size = nextNodes.size();
			
			for (int i = 0; i < size; i++) {
				TreeNode *cur = nextNodes.front();
				nodes.push_back(cur->val);
				nextNodes.pop();
				
				if (cur->left) nextNodes.push(cur->left);
				if (cur->right) nextNodes.push(cur->right);
			}
			
			treeByLevel.push_back(nodes);
		}
		
		return treeByLevel;
	}
};