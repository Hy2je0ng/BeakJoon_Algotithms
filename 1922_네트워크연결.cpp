#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

struct Edge{
	int nodeA;
	int nodeB;
	int weight;
};

struct Comp{
	bool operator()(const Edge& a, const Edge& b){
		return a.weight > b.weight;
	}
};

int find(int node){
	if(node == parent[node]) return node;
	else return find(parent[node]);
}

void unionF(int a, int b){
	int pA = find(a);
	int pB = find(b);
	parent[pA] = pB;
}

int main(){	

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i <= n; i++){
		parent.push_back(i);
	}	
	
	priority_queue<Edge, vector<Edge>, Comp> pq;
	
	for(int i = 0; i < m; i++){
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		
		pq.push({a, b, w});
	}
	
	int edge = 0, result = 0;
	
	while(edge < n-1 || !pq.empty()){
		Edge top = pq.top();
		pq.pop();
		
		if(find(top.nodeA)!= find(top.nodeB)){
			edge++;
			result += top.weight;
			unionF(top.nodeA, top.nodeB);
		}
	}
	
	printf("%d", result);
	
	return 0;
}
