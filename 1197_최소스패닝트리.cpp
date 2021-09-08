#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int nodeA;
	int nodeB;
	int weight;
};

struct Comp{
	bool operator()(const Edge& A, const Edge& B){
		return A.weight > B.weight;
	}
};

vector<int> parent;

int find(int node){
	if(node == parent[node]) return node;
	else return find(parent[node]);
}

void unionF(int a, int b){
	int pA = find(a);
	int pB = find(b);
	
	parent[pA] = pB;
}

int main() {
	
	int v, e;
	scanf("%d %d", &v, &e);
	
	priority_queue<Edge, vector<Edge>, Comp> edges;
	
	int edge = 0;
	int result = 0;

	for(int i = 0; i <= v; i++){
		parent.push_back(i);
	}	
	
	for(int i = 0; i < e; i++){
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		
		edges.push({a, b, w});
	}
	
	while(edge < v - 1 || !edges.empty()){
		Edge minE = edges.top();
		edges.pop();
		
		if(find(minE.nodeA) != find(minE.nodeB)){
			unionF(minE.nodeA, minE.nodeB);
			result += minE.weight;
			edge++;
		}
	}
	
	printf("%d", result);
	
	return 0;
}
