#include <iostream>
using namespace std;
struct node {
	int x, y, step;
} q[100010];
const int N = 1003;
int qr, vis[N][N], dis[N][N], ql=1;
const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {2, 1, -1, -2, 2, 1, -1, -2};
int main() {
	for(int i=0;i<=1000;i++) {
		for(int j=0;j<=1000;j++) {
			dis[i][j] = -1;
		}
	}
	int sx, sy, n, m;
	cin>>n>>m>>sx>>sy;
	q[++qr] = {sx, sy, 0};
	vis[sx][sy] = 1;
	while (qr-ql+1) {
		node f = q[ql++];
		for (int i = 0; i < 8; i++) {
			int tx = f.x + dx[i], ty = f.y + dy[i];
			dis[f.x][f.y] = f.step;
			if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
			if (vis[tx][ty]) continue;
			vis[tx][ty] = 1;
			q[++qr] = {tx, ty, f.step + 1};
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) printf("%-5d", dis[i][j]);
		cout<<'\n';
	}
	return 0;
}