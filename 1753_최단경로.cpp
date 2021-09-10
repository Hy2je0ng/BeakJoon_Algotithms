#include <bits/stdc++.h>
#define INF 1E9

using namespace std;

struct Edge{
	int id;
	int cost;
};

struct Comp{
	bool operator()(const Edge& a, const Edge& b){
		return a.cost > b.cost;
	}
};

vector<vector<Edge>> adjList;
vector<int> dist;

void dijkstra(int start){
	priority_queue<Edge, vector<Edge>, Comp> pq;
	
	dist[start] = 0;
	pq.push({start, dist[start]});
	
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		
		if(dist[now.id] < now.cost) continue;
		
		int size = adjList[now.id].size();
		for(int i = 0; i < size; i++){
			Edge next = adjList[now.id][i];
			
			if(dist[next.id] > now.cost + next.cost){
				dist[next.id] = now.cost + next.cost;
				pq.push({next.id, dist[next.id]});
			}
		}
	}
}

int main(){
	
	int v, e, start;
	scanf("%d %d %d", &v, &e, &start);
	
	for(int i = 0; i <= v; i++){
		dist.push_back(INF);
		vector<Edge> tmp;
		adjList.push_back(tmp);
	}	
	
	for(int i = 0; i < e; i++){
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		adjList[a].push_back({b, w});
	}
	
	dijkstra(start);
	
	for(int i = 1; i < dist.size(); i++){
		if(dist[i] < INF){
			printf("%d\n", dist[i]);
		}
		else{
			printf("INF\n");
		}
	}
	
	return 0;
}
