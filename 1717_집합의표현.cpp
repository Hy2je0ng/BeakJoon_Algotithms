#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> parent;

void init() {
	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
	}
}

int find(int a) {
	if (parent[a] == a)return a;
	return parent[a] = find(parent[a]);
}

void unionF(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	parent[pb] = pa;
}

int main() {
	scanf("%d %d", &n, &m);

	init();

	for(int i = 0; i < m; i++){
        int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);
       
		if (cmd == 0) { // ÇÕÁýÇÕ
			unionF(a, b);
		}
		else {
			if (find(a) == find(b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
    }
  
	return 0;
}
