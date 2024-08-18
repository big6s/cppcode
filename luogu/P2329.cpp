#include <bits/stdc++.h>
using namespace std;
int n, m, a[55], b[1100];
int w, l, r, mid, tot, sum[1100];
bool dfs(int x, int l) {
	if (tot - w < sum[mid]) return 0;
	if (!x) return 1;
	bool f = 0;
	for (int i = l; i <= n; i++) {
		if (a[i] >= b[x]) {
			a[i] -= b[x];
			if (a[i] < b[1]) w += a[i];
			if (b[x - 1] == b[x]) f = dfs(x - 1, i);
			else f = dfs(x - 1, 1);
			if (a[i] < b[1]) w -= a[i];
			a[i] += b[x];
			if (f) return 1;
		}
	}
	return 0;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tot += a[i]; //求和
	}
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + b[i];
	while (sum[m] > tot && m) m--; //找到sum[x]使sum[x]<=tot
	int l = 0, r = m;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (dfs(mid, 1)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}