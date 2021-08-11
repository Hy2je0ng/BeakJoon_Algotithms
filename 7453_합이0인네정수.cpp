#include <bits/stdc++.h>

using namespace std;

bool comp(const int& a, const int& b) {
	return a > b;
}

int main() {

	int n;
	scanf("%d", &n);

	vector<int> A, B, C, D;

	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	vector<int> AB, CD;

	// AB (A + B)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
		}
	}

	// CD (C + D)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			CD.push_back(C[i] + D[j]);
		}
	}

	// sorting
	sort(AB.begin(), AB.end()); 
	sort(CD.begin(), CD.end(), comp);

	// two pointer
	int ptab = 0, ptcd = 0;
    long long int result = 0;

	while (ptab < AB.size() && ptcd < CD.size()) {

		int currentAB = AB[ptab];
		int target = -currentAB;

		if (CD[ptcd] == target) {
            int ab = 0, cd = 0;
            while(AB[ptab] == currentAB && ptab < AB.size()){
                ab++;
                ptab++;
            }
            while(CD[ptcd] == target && ptcd < CD.size()){
                cd++;
                ptcd++;
            }
            result += (long long int) ab * cd;
		}
		else if (CD[ptcd] > target) {
			ptcd++;
		}
		else {
			ptab++;
		}

	}

	printf("%lld\n", result);
		
	return 0;
}
