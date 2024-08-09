#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n, m;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
char mp[N][N];
bool vis[N][N];
void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
			if (mp[tx][ty] == 'W' && !vis[tx][ty]) {
				vis[tx][ty]=1;
				dfs(tx, ty);
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mp[i][j] == 'W' && !vis[i][j]) {
				vis[i][j]=1;
				dfs(i, j);
				sum++;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}