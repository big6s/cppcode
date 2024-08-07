#include <iostream>
using namespace std;
const int N=10000+10, M=1000000+10;
char mp[N][N];
int vis[N][N], n, m, ans[M], cnt;
const int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
void dfs(int x, int y, int t) {
	vis[x][y] = t;
	ans[t]++;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 1 || ty > n || tx > n || ty < 1 || vis[tx][ty] || mp[tx][ty] == mp[x][y]) continue;
		dfs(tx, ty, t);
	}
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; i++) cin>>(mp[i]+1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vis[i][j]) {
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}
	while (m--) {
		int x, y;
		cin>>x>>y;
		cout<<ans[vis[x][y]]<<'\n';
	}
	return 0;
}