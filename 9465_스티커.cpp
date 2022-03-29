// Beajoon 9465 스티커 : Dynamic Programming
// author : hy2je0ng

// first and second 행 [0]번째에 저장
// dp의 값은  해당 위치까지의 최댓값을 저장
// dp[1][i] = max(같은 행 이전 값dp[1][i-1], 다른 행 이전 값dp[2][i-1] + 자기 점수)
// dp[2][i] = max(같은 행 이전 값dp[2][i-1], 다른 행 이전 값dp[1][i-1] + 자기 점수)

#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	
	for(int t = 0; t < tc; t++){
		int n;
		scanf("%d", &n);
		vector<vector<int>> arr(2 + 1, vector<int> (n + 1, 0));
		vector<vector<int>> dp(2 + 1, vector<int> (n + 1, 0));
		
		for(int i = 1; i <= 2; i++){
			for(int j = 1; j <= n; j++){
				int num;
				scanf("%d", &num);
				arr[i][j] = num;
			}
		}
		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];
		
		for(int i = 1; i <= n; i++){
			dp[1][i] = max(dp[1][i-1], dp[2][i-1] + arr[1][i]);
			dp[2][i] = max(dp[2][i-1], dp[1][i-1] + arr[2][i]);	
		}
		printf("%d\n", max(dp[1][n], dp[2][n]));
	}
	return 0;
}
