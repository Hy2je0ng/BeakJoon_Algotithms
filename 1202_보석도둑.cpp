#include <bits/stdc++.h>

using namespace std;

struct Jewerly{
	int weight;
	int value;
};

bool weightComp(const Jewerly& a, const Jewerly&b){
	return a.weight < b.weight;
}

struct valueComp{
	bool operator()(const Jewerly& a, const Jewerly& b){
		return a.value < b.value;
	}
};

int main(){	
	int n, k;
	scanf("%d %d", &n, &k);
	
	vector<Jewerly> jew;
	vector<int> bag;
	
	for(int i = 0; i < n; i++){
		int m, v;
		scanf("%d %d", &m, &v);		
		jew.push_back({m, v});
	}
	
	for(int i = 0; i < k; i++){
		int c;
		scanf("%d", &c);		
		bag.push_back(c);	
	}
		
	sort(jew.begin(), jew.end(), weightComp);
	sort(bag.begin(), bag.end());
	
	long long int result = 0;
	priority_queue<Jewerly, vector<Jewerly>, valueComp> pq;
   
	int bagIdx = 0;
	for(int i = 0; i < bag.size(); i++){
		while(bagIdx < n & jew[bagIdx].weight <= bag[i]){
			pq.push(jew[bagIdx]);
			bagIdx++;
		}
		
		if(!pq.empty()){
			result += pq.top().value;
			pq.pop();
		}
	}	
	
	printf("%lld", result);
	
	return 0;
}
