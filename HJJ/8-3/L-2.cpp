#include <bits/stdc++.h>
using namespace std;
int t, m, a, b, c, delta;
void you(int delta) { //有理数
	int p = -b + sqrt(delta), w = -b - sqrt(delta);
	int q = 2 * a;
	if (p * 1.0 / q < w * 1.0 / q) p = w;
	if (p % q == 0 && w % q == 0) {
		cout << p / q;
		return;
	}
	if ((p < 0 && q > 0) || (p > 0 && q < 0)) cout << '-';
	p = abs(p);
	q = abs(q);
	int k = __gcd(p, q);
	p /= k;
	q /= k;
	if (q == 1) cout << p;
	else if (p == 0) cout << 0;
	else printf("%d/%d", p, q);
}
int f(int delta) {
	int ans = 1;
	for (int i = 2; i * i <= delta; i++)
		while (delta % (i * i) == 0) {
			ans *= i;
			delta /= i * i;
		}
	return ans;
}
void wu(int delta) { //无理数
	if (-b * 1.0 / (2 * a)) {
		you(0);
		cout << '+';
	}
	int k = f(delta);
	delta /= k * k;
	double q2 = fabs(1.0 * k / (2 * a));
	if (q2 == 1) printf("sqrt(%d)", delta);
	else if (q2 == floor(q2)) printf("%.0f*sqrt(%d)", q2, delta);
	else if (1 / q2 == floor(1 / q2) && 1 / q2 != 0) printf("sqrt(%d)/%.0f", delta, 1 / q2);
	else {
		int c = k;
		int d = 2 * a;
		int x = __gcd(c, d);
		c /= x;
		d /= x;
		if ((c < 0 && d > 0) || (c > 0 && d < 0)) {
			c = abs(c);
			d = abs(d);
		}
		if (c != 1) cout << abs(c) << '*';
		printf("sqrt(%d)/%d", delta, d);
	}
	cout << endl;
}
int main() {
	cin >> t >> m;
	while (t--) {
		cin >> a >> b >> c;
		delta = b * b - 4 * a * c;
		if (delta < 0) cout << "NO" << endl;
		else {
			if (sqrt(delta) == floor(sqrt(delta))) {
				you(delta);
				cout << endl;
			} else wu(delta);
		}
	}
	return 0;
}