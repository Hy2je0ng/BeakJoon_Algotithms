#include <bits/stdc++.h>

using namespace std;

int rcm[110] = {0, };
int dur[110] = {0, };
	
bool comp(const int o1, const int o2){
	if(rcm[o1] == rcm[o2]){
		if(dur[o1] < dur[o2]){
			return true;
		}
		else{
			return false;
		}
	}
	else if(rcm[o1] > rcm[o2]){
		return true;
	}
	else{
		return false;
	}
}

int main() {
	int n, c;
	vector<int> photo;
	
	scanf("%d %d", &n, &c);
	
	for(int i = 0; i < c; i++){
		int x;
		scanf("%d ", &x);
		
		rcm[x]++;
		
		for(int j = 0; j < photo.size(); j++){
			dur[photo[j]]++;
		}
		
		bool exist = false;
		
		for(int j = 0; j < photo.size(); j++){
			if(photo[j] == x){
				exist = true;
				break;
			}
		}
		
		if(!exist){
			if(photo.size() < n){
				photo.push_back(x);
			}else{
				sort(photo.begin(), photo.end(), comp);
				rcm[photo.back()] = 0;
				dur[photo.back()] = 0;
				photo.back() = x;
			}
		}
		
	}
	
	sort(photo.begin(), photo.end());
	
	for(int i = 0; i < photo.size(); i++){
		printf("%d ", photo[i]);
	}
	
}
