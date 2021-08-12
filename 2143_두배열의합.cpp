#include<bits/stdc++.h>

using namespace std;

bool comp(const int& a, const int& b){
	return a > b;
}

int main(){
	
	int T, n, m;
	vector<int> A, B;
	vector<long> subA, subB;
	
	scanf("%d %d", &T, &n);
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		A.push_back(x);
	}
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int x;
		scanf("%d", &x);
		B.push_back(x);
	}
	
	for(int i = 0; i < n; i++){
		long sum = 0;
		for(int j = i; j < n; j++){
			sum += A[j];
			subA.push_back(sum);
		}
	}
	
	for(int i = 0; i < m; i++){
		long sum = 0;
		for(int j = i; j < m; j++){
			sum += B[j];
			subB.push_back(sum);
		}
	}
	
	int ptA = 0, ptB = 0;
	long result = 0;
	
	sort(subA.begin(), subA.end());
	sort(subB.begin(), subB.end(), comp);
	
	while(ptA < subA.size() && ptB < subB.size()){
		long currentA = subA[ptA];
		long target = T - currentA;
		
		if(subB[ptB] > target){
			ptB ++;
		}
		else if(subB[ptB] == target){
			long countA = 0;
			long countB = 0;
			
			while(ptA < subA.size() && subA[ptA] == currentA){
				ptA ++;
				countA ++;
			}
			
			while(ptB <subB.size() && subB[ptB] == target){
				ptB ++;
				countB ++;
			}
			
			result += countA * countB;
		}
		else{
			ptA ++;
		}
	}
			
	printf("%ld", result);
	
	return 0;
}
