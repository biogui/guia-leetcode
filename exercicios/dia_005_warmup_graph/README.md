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
        map<int, pair<int, vector<int>>> employeesMap;
        for (Employee* emp : employees) {
            employeesMap[emp->id] = make_pair(emp->importance, emp->subordinates);
        }
        
        stack<int> next_nodes;
        next_nodes.push(id);
        
        int importanceSum = 0;
        while (!next_nodes.empty()) {
            pair<int, vector<int>> cur = employeesMap[next_nodes.top()];
            next_nodes.pop();
            
            importanceSum += cur.first;
            
            for (int sub : cur.second) next_nodes.push(sub);
        }
        
        return importanceSum;
    }
};
```

### Resolução
* DFS

### Complexidades
* Espaço: O(n)
* Tempo: O(n)
