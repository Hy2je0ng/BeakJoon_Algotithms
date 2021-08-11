#include <bits/stdc++.h>
#define COL 3

using namespace std;

int small(int, int);
int big(int, int);
int small(int, int, int);
int big(int, int, int);

int main() {
	
	int n, max, min;
	scanf("%d", &n);

	int dpMin[COL] = {0, };
	int dpMax[COL] = {0, };
	
	for(int i = 1; i <= n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		int tmp0 = dpMax[0], tmp1 = dpMax[1], tmp2 = dpMax[2];
		dpMax[0] = big(tmp0, tmp1) + a;
		dpMax[1] = big(tmp0, tmp1, tmp2) + b;
		dpMax[2] = big(tmp1, tmp2) + c;
		
		tmp0 = dpMin[0], tmp1 = dpMin[1], tmp2 = dpMin[2];
		dpMin[0] = small(tmp0, tmp1) + a;
		dpMin[1] = small(tmp0, tmp1, tmp2) + b;
		dpMin[2] = small(tmp1, tmp2) + c;

	}
	
	max = big(dpMax[0], dpMax[1], dpMax[2]);	
	min = small(dpMin[0], dpMin[1], dpMin[2]);
	
	printf("%d %d", max, min);
	
	return 0;
}

int small(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int big(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int small(int a, int b, int c){
	if(a < b){
		return small(a, c);
	}
	else{
		return small(b, c);
	}
}

int big(int a, int b, int c){
	if(a > b){
		return big(a, c);
	}
	else{
		return big(b, c);
	}
}
