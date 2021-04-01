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
