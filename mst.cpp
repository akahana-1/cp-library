#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

//プリム法
int prim(int n,int s){ //第一引数は要素数,第二引数は始める頂点
	typedef pair<int,int> P; //第一引数が辺のコスト,第二引数が辺の行き先
	bool ischeck[n];
	int mincost = 0;
	priority_queue<P,vector<P>,greater<P> > pq;
	P p,tp;
	for(int i = 0;i < n;++i){
		ischeck[i] = false;
		if(cost[s][i] != -1){
			p.first = cost[s][i];
			p.second = i;
			pq.push(p);
		}
	}
	ischeck[s] = true;
	while(!pq.empty()){
		p = pq.top();
		pq.pop();
		if(ischeck[p.second]) continue;
		else{
			ischeck[p.second] = true;
			mincost += p.first;
			for(int i = 0;i < n;++i){
				if(cost[p.second][i] != -1){
					tp.first = cost[p.second][i];
					tp.second = i;
					pq.push(tp);
				}
			}
		}
	}
	return mincost;
}
