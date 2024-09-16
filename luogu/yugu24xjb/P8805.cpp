#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
vector<int> mp[N << 1];
int sum[N], a[N], dep[N], fa[N][20], n, m;
void dfs(int u, int ufa) {
	dep[u] = dep[ufa] + 1;
	fa[u][0] = ufa;
	for (int i = 1; (1 << i) <= dep[u]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0; i < mp[u].size(); i++) {
		int v = mp[u][i];
		if (v == ufa)
			continue;
		sum[v] = sum[u] + a[v];
		dfs(v, u);
	}
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int d = dep[x] - dep[y];
	for (int i = 0; (1 << i) <= n; i++)
		if ((1 << i)&d) x = fa[x][i];
	if (x == y)	return x;
	for (int i = log2(n); i >= 0; i--) {
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}
int main() {
	cin >> n >> m;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, mp[u].push_back(v), mp[v].push_back(u);
	for (int i = 1; i <= n; i++)
		a[i] = mp[i].size(), sum[i] = mp[i].size();
	dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		cout << sum[u] + sum[v] - 2 * sum[lca(u, v)] + a[lca(u, v)] << endl;
	}
	return 0;
}