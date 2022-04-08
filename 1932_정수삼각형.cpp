// Beakjoon 1932 정수삼각형 - DP
// author : hy2je0ng
// date : 22.04.08

// 1. [i][j]는 [i-1][j-1], [i-1][j]에서 값을 받아올 수 있지만
// 2. [i][j]는 [i+1][j], [i+1][j+1]에 값을 보낼 수 있다.
// 2번 방법을 사용해 i는 0 ~ n-1 까지 돌면서 값 할당 

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector<vector<int> > arr(n, vector<int> (n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			int x;
			scanf("%d", &x);
			arr[i][j] = x;
		}
	}
	
	vector<vector<int> > dp(n, vector<int> (n, 0));
	dp[0][0] = arr[0][0];
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j <= i; j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + arr[i+1][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + arr[i+1][j+1]);
		}
	}
	
	int maxNum = 0;
	for(int i= 0; i < n; i++){
		maxNum = max(maxNum, dp[n-1][i]);
	}
	
	printf("%d", maxNum);	
	return 0;
}
