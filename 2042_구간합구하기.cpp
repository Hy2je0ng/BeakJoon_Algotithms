// Beakjoon 2042 구간 합 구하기 : Indexed Tree(인덱스 트리) 
// author : hy2je0ng
// date : 22.04.05

// Indexed Tree : data 갱신이 자주 일어날 때, 여러 번 구간 합을 구해야 할 때 사용
// 완전 이진 트리 (Perfect Binary Tree)로 구현.

// n - data 수 , m - 변경 횟수, k  - 구간 합 횟수 
// 1. n에 대해 n보다 크거나 같은 가장 작은 2의 제곱수 찾기(leafNode)
// 2. leafNode부터 data 순서대로 채우기
// 3. leafNode 전 노드부터 ~ 1(Root)노드 까지 left + right 합으로 채우기
// 4. m + k번 만큼 쿼리 수행 (cmd == 1 -> 갱신, cmd == 2 -> 구간 합 구하기)

// 데이터 갱신 (update)
// 현재 노드를 기준으로 부모노드(~ 루트노드) 방문하며 갱신되는 값만큼 더하기.

// 구간 합 구하기 (query)
// 현재 구간(left ~ right)을 전혀 포함하지 않을 때 return 0;
// 현재 구간을 모두 알 때 return tree[현재 노드 인덱스];
// 애매할 때 왼쪽 자식과 오른쪽 자식에게 물어보기 

#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

vector<lld> tree;

void update(int idx, lld diff){
	while(idx > 0){
		tree[idx] += diff;
		idx /= 2;
	}
}

lld query(int start, int end, int left, int right, int curIdx){    
	if(right < start || end < left){ // 값 사용 불가 
		return 0;
	}
	else if(left <= start && end <= right){ // 알아 
		return tree[curIdx];
	}
	else { // 자식에게 물어봐 
		int mid = (start + end) / 2;
		lld leftSum = query(start, mid, left, right, curIdx * 2);
		lld rightSum = query(mid+1, end, left, right, curIdx * 2 + 1);
		return leftSum + rightSum;
	}
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	// 1. find number of leafNode 
	int leafNode = 1;
	while(leafNode < n){
		leafNode *= 2;
	}
	
	// 2. Fill Leaf node
	tree.resize((leafNode * 2), 0);
	
	for(int i = leafNode; i < leafNode + n; i++){
		lld x;
		scanf("%lld", &x);
		tree[i] = x;
	}
	
	// 3. Fill Inner Node
	for(int i = leafNode - 1; i >= 1; i--){
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	
	// 4. Perform Query
	for(int i = 0; i < m+k; i++){
		lld cmd, a,  b;
		scanf("%lld %lld %lld", &cmd, &a, &b);
		
		if(cmd == 1){ // 값 갱신
			lld diff = b - tree[(leafNode -1) + a];
			update((leafNode -1) + a, diff);
		}
		else if(cmd == 2){ // 구간 합 
			lld sum = query(1, leafNode, a, b, 1);
			printf("%lld\n", sum);
		}
	}
	
	return 0;
}
