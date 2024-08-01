#include <iostream>
using namespace std;
const int N = 503;
int n, m, k, ans, axl, axr, ayl, ayr;
int sum[N][N], cnt[N][N];
char s[N][N];
bool check1(int xl, int xr, int yl, int yr) {
	if (cnt[xr][yr] - cnt[xr][yl - 1] - cnt[xl - 1][yr] + cnt[xl - 1][yl - 1] > 0) return 0;
	if (sum[xr][yr] - sum[xr][yl - 1] - sum[xl - 1][yr] + sum[xl - 1][yl - 1] <= k) return 1;
	if (sum[xr][yr] - sum[xr][yl - 1] - sum[xl - 1][yr] + sum[xl - 1][yl - 1] >=
		(xr - xl + 1) * (yr - yl + 1) - k)
		return 1;
	return 0;
}
bool check2(int xl, int xr, int yl, int yr) {
	return cnt[xr][yr] - cnt[xr][yl - 1] - cnt[xl - 1][yr] + cnt[xl - 1][yl - 1] == (xr - xl + 1) * (yr - yl + 1);
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> (s[i] + 1);
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (s[i][j] == 'G');
			cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1] + (s[i][j] == 'P');
		}
	}
	for (int yl = 1; yl <= m; yl++) {
		for (int yr = yl; yr <= m; yr++) {
			int l = 1, r = 0;
			while (r <= n && l <= n) {
				while (r < n && check1(l, r + 1, yl, yr)) r++;
				if ((yr - yl + 1) * (r - l + 1) > ans) {
					axl = l;
					axr = r;
					ayl = yl;
					ayr = yr;
					ans = (yr - yl + 1) * (r - l + 1);
				}
				l++;
			}
		}
	}
	for (int yl = 1; yl <= m; yl++) {
		for (int yr = yl; yr <= m; yr++) {
			int l = 1, r = 0;
			while (r <= n && l <= n) {
				while (r < n && check2(l, r + 1, yl, yr)) r++;
				if ((yr - yl + 1) * (r - l + 1) > ans) {
					axl = l;
					axr = r;
					ayl = yl;
					ayr = yr;
					ans = (yr - yl + 1) * (r - l + 1);
				}
				l++;
			}
		}
	}
	cout << ans << '\n';
	if (check2(axl, axr, ayl, ayr)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cout << s[i][j];
			cout << '\n';
		}
	} else if (sum[axr][ayr] - sum[axr][ayl - 1] - sum[axl - 1][ayr] +
				   sum[axl - 1][ayl - 1] <=
			   k) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i >= axl && i <= axr && j >= ayl && j <= ayr) cout << 'B';
				else cout << s[i][j];
			}
			cout << '\n';
		}
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i >= axl && i <= axr && j >= ayl && j <= ayr) cout << 'G';
				else cout << s[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}