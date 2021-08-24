#include <bits/stdc++.h>

using namespace std;

struct Data{
	int idx;
	int value;
};

struct Comp{
	bool operator()(const Data& a, const Data& b){
		return a.value > b.value;
	}
};

int main() {
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n, l;
	cin >> n >> l;
	
	priority_queue<Data, vector<Data>, Comp> pq;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		
		pq.push({i, x});
		
		while(pq.top().idx < i - l + 1){
			pq.pop();
		}
		
		cout << pq.top().value << ' ';	
	}
	return 0;
}
