#include <iostream>
using namespace std;
const int N=203;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m, a[N][N], s[N][N], ans = -1;
int dfs(int x, int y) {
	if (s[x][y]) return s[x][y];
	int w = 1;
	for (int i = 0; i < 4; i++) {
		int tx = dx[i] + x, ty = dy[i] + y;
		if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
		if (a[x][y] > a[tx][ty]) w = max(w, dfs(tx, ty) + 1);
	}
	return s[x][y] = w;
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin>>a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = max(ans, dfs(i, j));
	cout<<ans;
	return 0;
}