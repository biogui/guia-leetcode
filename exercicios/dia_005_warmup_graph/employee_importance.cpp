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