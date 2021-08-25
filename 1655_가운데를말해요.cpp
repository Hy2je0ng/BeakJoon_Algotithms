#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	scanf("%d", &n);
	
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		
		if(maxHeap.size() <= minHeap.size()){
			maxHeap.push(x); 
		}
		else{
			minHeap.push(x);
		}
		
		while(!minHeap.empty() && maxHeap.top() > minHeap.top()){
			int max = maxHeap.top();
			int min = minHeap.top();
			 
			maxHeap.pop();
			minHeap.pop();
			
			maxHeap.push(min);
			minHeap.push(max);
		}
		
		printf("%d\n", maxHeap.top());
		
	}
	
	return 0;
}
