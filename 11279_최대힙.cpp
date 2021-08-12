#include <bits/stdc++.h>

using namespace std;

int n;
vector<long> heap;

void pop(){
	if(heap.size() > 1){
		printf("%d\n", heap[1]);
		
		int node = 1, lastIdx = heap.size() - 1;
		heap[node] = heap[lastIdx];
		heap.erase(heap.begin() + lastIdx);
		
		while(true){
			int left = node * 2, right = node * 2 + 1;
			if(left >= lastIdx) break;
			
			int maxV = heap[left], maxPos = left;
			
			if(right < lastIdx && maxV < heap[right]){
				maxV = heap[right];
				maxPos = right;						
			}
			
			if(heap[node] < maxV){
				swap(heap[node], heap[maxPos]);
				node = maxPos;
			}else{
				break;
			}
		}
	}else{
		printf("0\n");
	}
}

void push(int x){
	heap.push_back(x);
	int node = heap.size() - 1, parent = node / 2;
	
	while(true){
		if(node == 0 && heap[node] < heap[parent]) break;
		
		if(node > 1 && heap[node] > heap[parent]){
			swap(heap[node], heap[parent]);
			node = parent;
			parent = node / 2;
		}else{
			break;
		}
	}
}

int main(){
	
	scanf("%d", &n);
	heap.push_back(0);
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		
		if(x == 0){
			pop();
		}else{
			push(x);
		}
	} 
	
	return 0;
}
