// Beakjoon 2293 동전 1 : Dynamic Programming
// author : hy2je0ng

// 각 동전 index를 1 ~ n이라고 하면
// dp[j]는 1 ~ i번째의 동전 조합으로 j가치를 만들 수 있는 경우의 수를 누적 
// dp[j] += dp[j-value];
// 현재 동전을 가지고 있는 경우 1 + 이전 동전으로 만들 수 있는 경우의 수 + [현재 가치 - 현재 동전 가치]를 만들 수 있는 경우의 수 
 
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	vector<int> values(n+1, 0);
	for(int i = 1; i <= n; i++){
		int v;
		scanf("%d", &v);
		values[i] = v;
	}
	
	vector<int> dp(k+1, 0);
	for(int i = 1; i <= n; i++){
		int value = values[i];
		dp[value] += 1;
		for(int j = 1; j <= k; j++){
			if(value <= j){
				dp[j] += dp[j-value];
			}
		}
	}
	
	printf("%d", dp[k]);
	return 0;
}
