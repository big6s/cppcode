#include <iostream>
using namespace std;
const int N=50010, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
struct node {
	int x, y, time;
} p, q[N];
const int M=305;
int m, x, y, t, nx, ny, time1[M][M], c[M][M];
int ql=1,qr;
int main() {
	cin >> m;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++) time1[i][j] = -1;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> t;
		if (t < time1[x][y] || time1[x][y] == -1) time1[x][y] = t;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && (time1[nx][ny] == -1 || t < time1[nx][ny]))
				time1[nx][ny] = t;
		}
	}
	c[0][0] = 1;
	q[++qr]={0,0,0};
	while (qr-ql+1) {
		node p = q[ql++];
		for (int i = 0; i < 4; i++) {
			nx = p.x + dx[i], ny = p.y + dy[i];
			if (nx >= 0 && ny >= 0 && c[nx][ny] == 0 && (time1[nx][ny] == -1 || p.time + 1 < time1[nx][ny])) {
				node txt={nx,ny,p.time+1};
				c[nx][ny] = 1;
				q[++qr]=txt;
				if (time1[nx][ny] == -1) {
					cout << txt.time;
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}