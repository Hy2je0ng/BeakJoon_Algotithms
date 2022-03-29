// Beakjoon 12865 평범한 배낭 : Dynamic Programming - knapsack 
// author : hy2je0ng
// date : 2022.03.29

// dp[i][j] : i - 물품 index, j - 담을 수 있는 무게
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
// 이전 물품까지 값, 이전 물품에서 현재 무게 뺸 만큼 + 현재 가치 중 max value 

#include <bits/stdc++.h>

using namespace std;

struct Product{
	int weight;
	int value;
};

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	vector<Product> p(n + 1, {0, 0});
	for(int i = 1; i <= n; i++){
		int w, v;
		scanf("%d %d", &w, &v);
		p[i] = {w, v};
	}
	
	vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = dp[i-1][j];
			if(j - p[i].weight >= 0)
				dp[i][j] = max(dp[i][j], dp[i-1][j-p[i].weight] + p[i].value);
		}
	}
	
	printf("%d", dp[n][k]);
	return 0;
}
