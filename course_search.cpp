#include <queue>
#include <map>
#include <functional>
#include <vector>

//ダイクストラ法
int dijkstra(int s,int g,int n){ //第一引数は開始頂点,第二引数は終了頂点,第三引数は要素数
	const int INF = 10000000;
	typedef pair<int,int> P; //第一引数がその点のコスト,第二引数がその点の座標
	priority_queue<P,vector<P>,greater<P> > pq; //greater書かないと死にます
	P p,tp;
	for(int i = 0;i < n;++i){
		p.first = INF;
		p.second = i;
		if(i == s) p.first = 0;
		pq.push(p);
	}
	while(!pq.empty()){
		p = pq.top();pq.pop();
		if(p.second == g) break;
		for(int i = 0;i < n;++i){
			tp.first = p.first + edge[p.second][i]; //擬似コードなのでそのままパクるな
			tp.second = i;
			pq.push(tp);
		}
	}
	return p.first;
}

//ワーシャルフロイド法
#include <algorithm>
void wf(int n){ //引数は頂点数
	for(int k = 0;k < n;++k){
		for(int i = 0;i < n;++i){
			for(int j = 0;j < n;++j){
				edge[i][j] = min(edge[i][j],edge[i][k] + edge[k][j]); //擬似コードなのでそのままパクるな
			}
		}
	}
	return;
}
