#include <iostream>
using namespace std;
const int N = 103;
int a[N], f[N<<1][N<<1];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i][i] = f[i + n][i + n] = (a[i] & 1);
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i + l - 1 <= (n << 1); i++) {
			int j = i + l - 1;
			f[i][j] = max(f[i][i] - f[i + 1][j], f[j][j] - f[i][j - 1]);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i][i] > f[i + 1][i + n - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}