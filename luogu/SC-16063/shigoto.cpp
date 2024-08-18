#include <iostream>
using ll = long long;
using namespace std;
const int N = 5e5 + 3;
const ll inf = 1e18;
int a[N], b[N], n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("shigoto.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		ll l = 0, r = 1e9, ans = 0;
		while (l <= r) {
			ll mid = (l + r) / 2, x = -inf, y = inf;
			for (int i = 1; i <= n; i++) {
				x = max(x, a[i] - mid * b[i]);
				y = min(y, a[i] + mid * b[i]);
			}
			if (x <= y) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}