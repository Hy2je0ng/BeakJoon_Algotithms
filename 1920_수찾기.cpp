#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	vector<int> data;
	vector<int> comp;

	scanf("%d", &n);
	
	for(int j = 0; j < n; j++){
		int x;
		scanf("%d", &x);
		data.push_back(x);
	}
	
	scanf("%d", &m);
	
	for(int j = 0; j < m; j++){
		int x;
		scanf("%d", &x);
		comp.push_back(x);
	}
	
	sort(data.begin(), data.end());
	
	for(int i = 0; i < m; i++){
		bool exist = false;
		
		//binary search
		int left = 0;
		int right = n;
			
		while(left <= right){
			int mid = (left + right) / 2;
			
			if(data[mid] == comp[i]){
				exist = true;
				break;
			}
			else if(data[mid] > comp[i]){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		
		if(exist){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
		
	}
	
	return 0;
}
