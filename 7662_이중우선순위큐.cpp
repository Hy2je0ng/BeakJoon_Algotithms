#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		int k;
		cin >> k;
		
		multiset<int> ms;
		
		for(int j = 0; j < k; j++){
			char c;
			int x;
			cin >> c >> x;
		
			if(c == 'I'){
				ms.insert(x);
			}
			else if(c == 'D'){
				if(!ms.empty()){
					if(x == 1){
						// 최댓값 삭제
						ms.erase(--ms.end());
					}
					else{
						// 최솟값 삭제 
						ms.erase(ms.begin());
					}
				}
			}
		}
		
		if(ms.empty()){
			cout << "EMPTY\n";
		}
		else{
			cout << *(--ms.end()) << " " << *(ms.begin()) << "\n";
		}
	}

	return 0;
}
