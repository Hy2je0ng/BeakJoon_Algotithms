#include <bits/stdc++.h>

using namespace std;

int main() {

	stack<int> st;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int x;
			scanf("%d", &x);

			st.push(x);
		}
		else if (s == "pop") {
			int top = -1;
			if (!st.empty()) {
				top = st.top();
				st.pop();
			}

			printf("%d\n", top);
		}
		else if (s == "size") {
			printf("%d\n", st.size());
		}
		else if (s == "empty") {
			int empty = 0;
			if (st.empty()) {
				empty = 1;
			}
			printf("%d\n", empty);
		}
		else if (s == "top") {
			int top = -1;
			if (!st.empty()) {
				top = st.top();
			}

			printf("%d\n", top);
		}

	}

	return 0;
}
