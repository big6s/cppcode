#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll N = 3030;
ll q, m, cnt, k, sqscd[N];
double a, b, c;
void print(ll x, ll y) {
	ll g = __gcd(x, y);
	x /= g, y /= g;
	if (y < 0) { //修改为-x/y，而不是x/-y
		y = -y;
		x = -x;
	}
	if (y == 1) printf("%lld", x);
	else printf("%lld/%lld", x, y);
}
bool check(ll &x) {
	bool f = 0;
	for (int i = 1; i <= cnt; i++) {
		if (sqscd[i] > x) break;
		if (x % sqscd[i] == 0) {
			k *= sqrt(sqscd[i]);
			f = 1;
			x /= sqscd[i];
		}
	}
	return f;
}
int main() {
	cin>>q>>m;
	for (int i = 2; i < N; i++) sqscd[++cnt] = i * i;
	while (q--) {
		k = 1;
		cin>>a>>b>>c;
		ll delta = b * b - 4 * a * c; // 判别式
		if (delta < 0) {
			puts("NO");
			continue;
		}
		if (!delta) {
			print(-b, 2 * a);
			putchar('\n');
			continue;
		}
		ll k = sqrt(delta);
		if (k * k == delta) { // 实数根
		 	// 选择较大的实数根
			if (((-b + k) / (2 * a)) > ((-b - k) / (2 * a))) print(-b + k, 2 * a);
			else print(-b - k, 2 * a);
			putchar('\n');
			continue;
		}
		if (b) { // 虚数根
			print(-b, 2 * a);
			putchar('+');
		}
		while (check(delta)); // 拆分
		ll x = 2 * a;
		ll v = __gcd(x, k);
		x /= v, k /= v;
		if (x == k) {
			printf("sqrt(%lld)\n", delta);
			continue;
		}
		if (k % x == 0) {
			ll d = abs(k / x);
			if (d == 1) printf("sqrt(%lld)\n", delta);
			else printf("%lld*sqrt(%lld)\n", d, delta);
			continue;
		}
		if (k == 1) {
			printf("sqrt(%lld)/%lld\n", delta, abs(x));
			continue;
		}
		printf("%lld*sqrt(%lld)/%lld\n", abs(k), delta, abs(x));
	}
	return 0;
}