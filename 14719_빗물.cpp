#include <bits/stdc++.h>

using namespace std;

const int MAX = 510;

int main(){
	
	int h, w;
	scanf("%d %d", &h, &w);
	
	int arr[MAX] = {0, };
	int left[MAX] = {0, };
	int right[MAX] = {0, };
	
	for(int i = 1; i <= w; i++){
		int height;
		scanf("%d", &height);
		arr[i] = height;
	}
	
	for(int i = 1; i < MAX; i++){
		left[i] = max(arr[i], left[i-1]);
	}
	
	for(int i = MAX - 2; i >= 0; i--){
		right[i] = max(arr[i], right[i+1]);
	}
	
	int result = 0;
	for(int i = 1; i < MAX; i++){
		result += (min(left[i] , right[i]) - arr[i]);
	}
	
	printf("%d", result);
	
	return 0;
}
