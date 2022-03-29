// Beakjoon 9461 파도반 수열 : Dynamic Programming
// author : hy2je0ng

// dp[1] = dp[2] = dp[3] = 1; 로 초기화
// dp[i] = d[i-2] + dp[i-3] 

// 결과 값은 long long int type
 
#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	
	vector<long long int> dp(4, 1);
	for(int t = 0; t < tc; t++){
		int n;
		scanf("%d", &n);
		int nextIdx = dp.size();
		if(n >= nextIdx){
			for(int i = nextIdx; i <= n; i++){
				dp.push_back(dp[i-2] + dp[i-3]);
			}
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}
