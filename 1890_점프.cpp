// Baekjoon 1890 점프 : Dynamic Programming (type 2)
// author : hy2je0ng

// (0, 0)부터 (n-1, n-1)까지 방문 
// dp[i][j] = (i, j)에 왔던 방문말 개수 
// 왼쪽에서 오른쪽, 위쪽에서 아래쪽으로 이동하기 때문에 순차 탐방 가능
// 경우의 수는 2^63 - 1 이므로 long long int 사용 

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector<vector<int>> move(n, vector<int> (n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;
			scanf("%d", &x);
			move[i][j] = x;
		}
	}
	
	vector<vector<long long int>> dp(n, vector<long long int> (n, 0));
	dp[0][0] = 1;

  for(int y = 0; y < n; y++){
		for(int x = 0; x < n; x++){
			if((y == n-1 && x == n-1) || (dp[y][x] <= 0)){ // 오른쪽 아래, 옮길 말이 없을 때
			    continue;
			}
			int nextY = y + move[y][x];
			int nextX = x + move[y][x];
			if(nextY < n) dp[nextY][x] += dp[y][x];
			if(nextX < n) dp[y][nextX] += dp[y][x];
		}
	}
	
	printf("%lld", dp[n-1][n-1]);
	return 0;
}
