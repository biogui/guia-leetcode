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
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        queue<TreeNode *> next_nodes;
        next_nodes.push(root);
        
        TreeNode *curr = root;
    
        while (!next_nodes.empty()) {
            vector<int> nodes;
            int size = next_nodes.size();
            
            for (int i = 0; i < size; i++) {
                curr = next_nodes.front();
                nodes.push_back(curr->val);
                next_nodes.pop();
                
                if (curr->left)  next_nodes.push(curr->left);
                if (curr->right) next_nodes.push(curr->right);
            }
            
            ans.push_back(nodes);    
        }       
        
        return ans;
    }
};
