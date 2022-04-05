// Baekjoon 14503 로봇 청소기 : 시뮬레이션
// author : hy2je0ng
// date : 2022.04.05

// d : 바라보는 방향 dir 기준 왼쪽 위치 dydx 저장
//      0(3) 
// 3(2)     1(0)
//      2(1)

//checkCount : 현재 위치 기준 사방향 모두 빈 공간이 아닐 때 check 변수
// cleanArea : 청소 영역 수

// 현재 위치 방향 기준 왼쪽(next)이 0이면 위치, 방향 이동
// next가 0이 아니면 checkCount 증가, 방향 이동
// checkCount가 4가 되었을 때, 뒤(back)가 1(벽)이면 중지, 아니면 이동해서 4방면 탐색 

#include <bits/stdc++.h>

using namespace std;

struct Pos{
	int y, x;
};

int main(){ 
	int n, m, dir;
	Pos now;
	
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &now.y, &now.x, &dir);
	
	vector<vector<int>> map(n, vector<int> (m, 1));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int state;
			scanf("%d", &state);
			map[i][j] = state;
		}
	}
	
	int checkCount = 0;
	int cleanArea = (map[now.y][now.x] == 0) ? 1 : 0;
	map[now.y][now.x] = 2;
	vector<Pos> d = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
	
	while(true){		
		if(checkCount >= 4){
			int backDir = (dir == 0) ? 3 : dir - 1;
			Pos back = {now.y + d[backDir].y, now.x + d[backDir].x};
			if(map[back.y][back.x] == 1) break;
			else{
				now = back;
				checkCount = 0;
				continue; 
			}
		}
		
		Pos next = {now.y + d[dir].y, now.x + d[dir].x};	
		if(map[next.y][next.x] == 0){ // 빈 공간 
			map[next.y][next.x] = 2;
			now = next;
			cleanArea += 1;
			checkCount = 0;
		}
		else{
			checkCount ++;
		}
		dir = (dir == 0) ? 3 : dir - 1; // 왼쪽 회전 
	}
	
	printf("%d", cleanArea);
	return 0;
}
