#include <bits/stdc++.h>

using namespace std;

const int MAX = 1010;

int main(){
	
	int n;
	scanf("%d", &n);
	
	int le[MAX] = {0, };
	int ri[MAX] = {0, };
	int arr[MAX] = {0, };
	
	for(int i = 0; i < n; i++){
		int l, h;
		scanf("%d %d", &l, &h);
		arr[l] = h;
	}
	
	for(int i = 1; i < MAX; i++){
		le[i] = max(arr[i], le[i-1]);
	}
	
	for(int i = MAX - 2; i >= 1; i--){
		ri[i] = max(arr[i], ri[i+1]);
	}
	
	int result = 0;
	for(int i = 0; i < MAX; i++){
		result += min(le[i], ri[i]);
	}
	
	printf("%d", result);
	
	return 0;
}
