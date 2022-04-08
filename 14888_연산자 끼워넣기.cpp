// Beakjoon 14888 연산자 끼워넣기 - Backtracking(순열)
// author : hy2je0ng
// date : 22.04.08

// +, -, *, / 순으로 개수만큼 op에 넣기
// opseq에 depth를 탐색하며 순서대로 op 인덱스 넣기
// 중복 방지를 위해 check 벡터 사용 
// depth가 op의 개수(n-1)가 되었을 때 순서대로 계산

#include <bits/stdc++.h>

using namespace std;

int n;
int maxResult = -1E9;
int minResult = 1E9;
vector<int> num, op, opSeq;
vector<bool> check;

int calcOp(int a, int b, int op){
	switch(op){
		case 0 :
			return a + b;
		case 1 :
			return a - b;
		case 2 : 
			return a * b;
		case 3 : 
			return a / b;
	}
}

int calculation(){
	int result = num[0];
	for(int i = 1; i < n; i++){
		result = calcOp(result, num[i], opSeq[i-1]);
	}
	return result;
}

void permutation(int depth){
	if(depth == n-1){
		int calc = calculation();
		maxResult = max(maxResult, calc);
		minResult = min(minResult, calc);
		return ;
	}
	
	for(int i = 0; i < n - 1; i++){
		if(check[i]){
			check[i] = false;
			opSeq[depth] = op[i];
			permutation(depth + 1);
			check[i] = true;	
		}
	}
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		num.push_back(x);
	}
	
	for(int i = 0; i < 4; i++){
		int c;
		scanf("%d", &c);
		for(int j = 0; j < c; j++){
			op.push_back(i);
		}
	}
	
	opSeq.resize(n-1, 0);
	check.resize(n-1, true);
		
	permutation(0);
	
	printf("%d\n%d", maxResult, minResult);
	return 0;
}
