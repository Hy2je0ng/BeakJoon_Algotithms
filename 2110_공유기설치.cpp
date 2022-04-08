// Beakjoon 2110 공유기 설치 - Binary Search
// author : hy2je0ng
// date : 22.04.08

// 1. 공평한 거리에 공유기 설치하는 것을 원함
// 2. 따라서 집의 index가 아닌 거리를 기준으로 이분탐색 해야함.
// 3. 공유기 설치된 위치로부터 mid(거리 값)보다 크거나 같으면 설치(count ++)
// 4. 3과정을 1 ~ n 까지 수행한 count 값이 c보다 작으면 범위 재조정
//    크거나 같으면 결과 저장 후에 더 큰 거리로 3 ~ 4 반복 

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	
	vector<int> home(n);
	for(int i = 0; i < n; i++){
		int d;
		scanf("%d", &d);
		home[i] = d;
	}
	
	sort(home.begin(), home.end());
	
	int result = 0;
	int left = 0, right = home.back();
	
	while(left <= right){
		int mid = (left + right) / 2;
		
		int count = 1, ipIdx = 0;
		for(int i = 1; i < n; i++){
			if(home[i] - home[ipIdx] >= mid){
				count++;
				ipIdx = i;
			}
		}
		
		if(count < c){
			right = mid - 1;
		}
		else{
			result = mid;
			left = mid + 1;
		}
	}
	
	printf("%d", result);
	return 0;
} 
