#include <iostream>
using ll = long long;
using namespace std;
ll ans[50];
ll a, b, n = 2;
bool fg;
const int ck[]={-2,-2,+2},pd[]={2,};
bool isprime(ll x) {
	if (x < 2) return 0;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}
void dfs(ll x, ll y, int t) {
	if (fg) return ;
	if (isprime(abs(x - y))) {
		cout << t + 1 << '\n' << a <<' ';
		for (int i = 1; i < t; i++) cout << ans[i] << ' ';
		cout << b << '\n';
		fg = 1;
		return;
	}
	if (x != 2) {
		for (int i = 1; i <= 3; i++) {
			if (i == 1 && isprime(x - 2)) {
				ans[t] = 2;
				dfs(2, y, t + 1);
			}
			if (i == 2 && isprime(x - 2)) {
				ans[t] = x - 2;
				dfs(x - 2, y, t + 1);
			}
			if (i == 3 && isprime(x + 2)) {
				ans[t] = x + 2;
				dfs(x + 2, y, t + 1);
			}
		}
	}
	else {
		if (isprime(y + 2)) {
			ans[t] = y + 2;
			dfs(y + 2, y, t + 1);
		}
	}
}
int main() {
	cin >> a >> b;
	if (isprime(abs(a - b))) {
		cout << n << '\n' << a << ' ' << b;
		return 0;
	}
	dfs(a, b, 1);
	if (!fg) cout << "-1";
	return 0;
}