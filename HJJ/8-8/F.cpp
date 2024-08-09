#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 203;
int n, m, a[N][N], f[N][N];
int main() {
	cin >> n >> m;
	int x = n, y = m / 2 + 1;
	memset(a, 128, sizeof(a));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = max({f[i - 1][j], f[i - 1][j - 1], f[i - 1][j + 1]}) + a[i][j];
		}
	}
	cout << max({f[x][y], f[x][y - 1], f[x][y + 1]}) << endl;
	return 0;
}