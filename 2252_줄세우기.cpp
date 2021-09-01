#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> student;
	vector<vector<int>> graph;

	for (int i = 0; i <= n; i++) {
		student.push_back(0);
		vector<int> a;
		graph.push_back(a);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		student[b] ++;
		graph[a].push_back(b);
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (student[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		printf("%d ", front);

		for (int i = 0; i < graph[front].size(); i++) {
			if (--student[graph[front][i]] == 0) {
				q.push(graph[front][i]);
			}
		}

	}
    
	return 0;
}
