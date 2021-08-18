#include <bits/stdc++.h>
#define MAX 4000010

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	// setPrime
	vector<int> prime;
	bool isPrime[MAX];
	
	for (int i = 0; i < MAX; i++) {
		isPrime[i] = true; // 초기화 
	}

	for (int i = 2; i < MAX; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			for(int j = 2 * i; j < MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}

	// 누적합 구하기
	vector<int> sum;
	int total = 0;
	
	sum.push_back(0);
	for(int i = 0; i < prime.size(); i++) {
		total += prime[i];
		sum.push_back(total);
	}

	int pt1 = 0, pt2 = 0;
	int result = 0;

	// two pointer : pt1 - pt2
	while ((pt2 <= pt1) && (pt1 < sum.size())) {
		int sub = sum[pt1] - sum[pt2];
		if (sub == n) {
			result++;
			pt1++;
		}
		else if (sub < n) {
			pt1++;
		}
		else {
			pt2++;
		}
	}

	printf("%d", result);

	return 0;
}

