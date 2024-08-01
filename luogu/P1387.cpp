#include <iostream>
#include <algorithm>
using namespace std;
const int N=103;
int a[N][N], n, m, f[N][N], ans;
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin>>a[i][j];
			if (a[i][j])
				f[i][j] = min({f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]}) + 1;
			ans = max(ans, f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}