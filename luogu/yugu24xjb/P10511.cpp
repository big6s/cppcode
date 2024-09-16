#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int mod = 998244353, N = 2e5 + 3;
int n, m, q;
int x[N], y[N], z[N], sum1[N], sum2[N];
signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i] >> z[i];
		z[i] %= mod;
		sum1[i] = (sum1[i - 1] + z[i] % mod * ((y[i] % mod - x[i] % mod + 1) % mod + mod % mod)) % mod;
		sum2[i] = (sum2[i - 1] + z[i] % mod * z[i] % mod * ((y[i] % mod - x[i] % mod + 1) % mod + mod % mod)) % mod;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int num1 = lower_bound(x + 1, x + m + 1, l) - x;
		int num2 = upper_bound(y + 1, y + m + 1, r) - y - 1;
		if (num1 > num2 + 1) {
			cout << "0\n";
			continue;
		}
		int cnt1 = (((sum1[num2] - sum1[num1 - 1]) % mod + mod) % mod + ((x[num1] - l) % mod + mod) % mod * z[num1 - 1] % mod + ((r - y[num2]) % mod + mod) % mod * z[num2 + 1] % mod) % mod;
		int cnt2 = (((sum2[num2] - sum2[num1 - 1]) % mod + mod) % mod + ((x[num1] - l) % mod + mod) % mod * z[num1 - 1] % mod * z[num1 - 1] % mod + ((r - y[num2]) % mod + mod) % mod * z[num2 + 1] % mod * z[num2 + 1] % mod) % mod;
		int ans = ((((r - l + 1) % mod + mod) % mod * cnt2 % mod - cnt1 % mod * cnt1 % mod) % mod + mod) % mod;
		cout << ans << "\n";
	}
	return 0;
}
