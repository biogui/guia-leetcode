# Day 005: Warm up - Graphs

## [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
```cpp=
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
```

### Resolução
* BFS

### Complexidades
* Espaço: O(n)
* Tempo: O(n)

---

## [Employee Importance](https://leetcode.com/problems/employee-importance/)
```cpp=
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, pair<int, vector<int>>> employees_map;
        for (Employee* emp : employees) {
            employees_map[emp->id] = make_pair(emp->importance, emp->subordinates);
        }
        
        stack<int> next_nodes;
        next_nodes.push(id);
        
        int importance_sum = 0;
        while (!next_nodes.empty()) {
            pair<int, vector<int>> cur = employees_map[next_nodes.top()];
            next_nodes.pop();
            
            importance_sum += cur.first;
            
            for (int sub : cur.second) next_nodes.push(sub);
        }
        
        return importance_sum;
    }
};
```

### Resolução
* DFS

### Complexidades
* Espaço: O(n)
* Tempo: O(n)
