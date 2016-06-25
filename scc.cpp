#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// Kosaraju Alogorithm
// g : adjacent list
vector<int> scc(const vector<vector<int> >& g){
	int n = g.size(), k = 0;
	vector<int> group(n, -1), visited(n, 0), rank(n, 0);
	vector<vector<int> > rg(n, vector<int>());
	for(int i = 0;i < n;++i){
		vector<int>::const_iterator it = g[i].begin();
		for(;it != g[i].end();++it){
			rg[*it].push_back(i);
		}
	}
	stack<int> s;
	for(int i = 0;i < n;++i){
		if(visited[i]) continue;
		s.push(i);
		while(!s.empty()){
			int now = s.top();
			bool pushed = false;
			visited[now] = true;
			vector<int>::const_iterator it = g[now].begin();
			for(;it != g[now].end();++it){
				if(!visited[*it]) {
					s.push(*it);
					pushed = true;
				}
			}
			if(pushed) continue;
			if(!rank[now]){
				rank[now] = s.size();
				s.pop();
			}
		}
	}
	for(int i = 0;i < n;++i){
		if(group[i] != -1) continue;
		s.push(i);
		while(!s.empty()){
			int now = s.top();
			s.pop();
			group[now] = k;
			vector<int>::const_iterator it = rg[now].begin();
			for(;it != rg[now].end();++it){
				if(group[*it] == -1) s.push(*it);
			}
		}
		++k;
	}
	return group;
}

int main(){
	int v, e, a, b, q;
	vector<vector<int> > graph;
	vector<int> group;
	cin >> v >> e;
	graph = vector<vector<int> >(v, vector<int>());
	for(int i = 0;i < e;++i){
		cin >> a >> b;
		graph[a].push_back(b);
	}
	group = scc(graph);
	cin >> q;
	for(int i = 0;i < q;++i){
		cin >> a >> b;
		cout << (int)(group[a] == group[b]) << endl;
	}
}
