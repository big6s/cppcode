#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
#define ll long long
using namespace std;
struct node {
	int x, y;
};
const int inf=0x3f3f3f3f, N=503;
const int dx[] = {0, 0, 1, -1} ,dy[] = {1, -1, 0, 0};
char a[N][N];
bool vis[N][N];
int d[N][N];
int n, m, x1, y1, x2, y2;
void bfs() {
	int x, y, nx, ny, w;
	memset(d, inf, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[x1][y1] = 0;
	deque<node> q;
	q.push_back(node{x1, y1});
	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		q.pop_front();
		if (vis[x][y]) continue;
		vis[x][y] = true;
		for (int i = 0; i < 4; ++i) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			w = a[nx][ny] != a[x][y];
			if (d[x][y] + w >= d[nx][ny]) continue;
			d[nx][ny] = d[x][y] + w;
			if (w == 0) q.push_front(node{nx, ny});
			else q.push_back(node{nx, ny});
		}
	}
}
int main() {
	while (1) {
		cin>>n>>m;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; ++i) {
			int j = 0;
			char c = getchar();
			while (c != '#' && c != '@') c = getchar();
			while (c == '#' || c == '@') {
				a[i][++j] = c;
				c = getchar();
			}
		}
		cin>>x1>>y1>>x2>>y2;
		++x1, ++y1, ++x2, ++y2;
		bfs();
		print(d[x2][y2]);
		putchar('\n');
	}
	return 0;
}