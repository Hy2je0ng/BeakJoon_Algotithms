// Beakjoon 18428 감시피하기 - Backtracking(조합)
// author : hy2je0ng
// date : 2022.04.08
 
// 빈 칸 - 0, 학생 - 1, 선생님 - 2, 장애물 - 3
// X- 0, S - 1, T - 2을 return하는 getState(c)로 state 반환 후
// state가 0이라면 emptyPos에 1이라면 studentPos에 위치 저장
// 3개의 장애물을 넣을 곳을 조합으로 탐색
// depth == 3일 때 studentPos 모든 위치에서 상 하 좌 우 탐색
// 장애물 전 선생님이 있으면 return false 

#include <bits/stdc++.h>

using namespace std;

struct Pos{
	int y, x;
};

int n;
bool poss = false;
vector< vector<int> > maps;
vector<Pos> emptyPos, studentPos;
vector<Pos> combArr(3);

int getState(char c){
	if(c == 'S') return 1;
	else if(c == 'T') return 2;
	return 0;
}

bool valid(){
	for(unsigned int i = 0; i < studentPos.size(); i++){
		Pos now = studentPos[i];
		
		// top 
		for(int i = now.y - 1; i >= 0; i--){
			int cur = maps[i][now.x];
			if(cur == 3){
				break;
			}
			else if(cur == 2){
				return false;
			}
		}
		
		// bottom
		for(int i = now.y + 1; i < n; i++){
			int cur = maps[i][now.x];
			if(cur == 3){
				break;
			}
			else if(cur == 2){
				return false;
			}
		}
		 
		// left
		for(int i = now.x - 1; i >= 0; i--){
			int cur = maps[now.y][i];
			if(cur == 3){
				break;
			}
			else if(cur == 2){
				return false;
			}
		}
		
		// right
		for(int i = now.x + 1; i < n; i++){
			int cur = maps[now.y][i];
			if(cur == 3){
				break;
			}
			else if(cur == 2){
				return false;
			}
		}
	}
	return true;
}

void combination(int depth, int next){
	if(poss) return ;
	
	if(depth == 3){
		if(valid()){
			poss = true;
		}
		return ;
	}
	
	for(unsigned int i = next; i < emptyPos.size(); i++){
		Pos now = emptyPos[i];
		maps[now.y][now.x] = 3;
		combination(depth + 1, i + 1);
		maps[now.y][now.x] = 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	maps.resize(n, vector<int> (n, 0));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c ;
			cin >> c;
			
			int state = getState(c);
			maps[i][j] = state;
			if(state == 0){
				emptyPos.push_back({i, j});
			}
			else if(state == 1){
				studentPos.push_back({i, j});
			}
		}
	}

	combination(0, 0);
	
	if(poss) printf("YES");
	else printf("NO");
	
	return 0;
}
