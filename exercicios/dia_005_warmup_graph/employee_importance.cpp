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