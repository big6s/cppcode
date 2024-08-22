#include <iostream>
using namespace std;
const int inf=0x3f3f3f3f;
int s[110][110];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	char a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a;
			if (a == '1') s[i][j]++;
			s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	int ans = inf;
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= m; y2++) {
					if (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] >= k) {
						ans = min(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
					}
				}
			}
		}
	}
	if (ans == inf) cout << 0;
	else cout << ans;
	return 0;
}
