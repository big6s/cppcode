#include <stdio.h>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
}q[100003];
const int N=503;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int x1[N], y1[N], x2[N], y2[N], ans[N][N];
bool vis[N][N];
int main() {
	queue<node> q;
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin>>x1[i]>>y1[i];
		vis[x1[i]][y1[i]] = 1;
		q.push((node) {
			x1[i], y1[i], 0
		});
	}
	for (int i = 1; i <= b; i++) cin>>x2[i]>>y2[i];
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = dx[i] + now.x, ty = dy[i] + now.y;
			if (tx < 1 || tx > n || ty < 1 || ty > m)
				continue;
			if (vis[tx][ty])
				continue;
			vis[tx][ty] = 1;
			ans[tx][ty] = now.step + 1;
			q.push((node) {
				tx, ty, now.step + 1
			});
		}
	}
	for (int i = 1; i <= b; i++)
		printf("%d\n", ans[x2[i]][y2[i]]);
	return 0;
}