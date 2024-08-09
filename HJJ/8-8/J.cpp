#include <bits/stdc++.h>
using namespace std;
const int N=206;
int f[N<<1][N<<1], a[N]; //f[l][r]表示[l,r]的数串的最大和
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[n + i] = a[i];
	}
	for (int i = 2; i <= n + 1; i++) {
		for (int l = 1; l <= 2 * n; l++) {
			int r = l + i - 1;
			if(r > 2*n) break;
			for (int k = l + 1; k <= r - 1; k++)
				f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res = max(res, f[i][n + i]);
	cout << res;
	return 0;
}