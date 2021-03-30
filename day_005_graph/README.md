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
    vector<inggt> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, pair<int, vector<int>>> employees_map;
        for (Employee* emp : employees) {
            employees_map[emp->id] = make_pair(emp->importance, emp->subordinates);
        }

        stack<int> s;
        s.push(id);

        pair<int, vector<int>> cur;
        int importance_sum = 0;
        while (!s.empty()) {
            cur = employees_map[s.top()];
            s.pop();

            importance_sum += cur.first;
            
            for (int sub : cur.second) s.push(sub);
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
