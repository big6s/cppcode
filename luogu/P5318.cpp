#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1e5+3;
struct edge {
	int u, v;
	friend bool operator<(edge x, edge y) {
		if (x.v == y.v) return x.u < y.u;
		return x.v < y.v;
	}
};
vector<int> e[N];
vector<edge> s;
bool vis1[N], vis2[N];
void dfs(int x) {
	vis1[x] = 1;
	cout << x << " ";
	for (int i = 0; i < e[x].size(); i++) {
		int v = s[e[x][i]].v;
		if (!vis1[v]) {
			dfs(v);
		}
	}
}
void bfs(int x) {
	queue <int> q;
	q.push(x);
	cout << x << " ";
	vis2[x] = 1;
	while (!q.empty()) {
		int f = q.front(); q.pop();
		for (int i = 0; i < e[f].size(); i++) {
			int v = s[e[f][i]].v;
			if (!vis2[v]) {
				q.push(v);
				cout << v << " ";
				vis2[v] = 1;
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		s.push_back({u, v});
	}
	sort(s.begin(), s.end());
	for (int i = 0; i < m; i++) e[s[i].u].push_back(i);
	dfs(1);
	cout << '\n';
	bfs(1);
	return 0;
}