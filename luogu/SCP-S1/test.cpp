#include <bits/stdc++.h>
using namespace std;
unsigned f(unsigned x) {
	x ^= x << 3;
	x ^= x >> 5;
	return x;
}
unsigned g(unsigned x) {
	return (x >> 5) ^ (x >> 2) ^ x ^ (x << 3);
}
int main() {
	freopen("test.in","r",stdin);
	unsigned y, l, r;
	cin >> y >> l >> r;
	for (unsigned long long i = l; i <= r; i++)
		if (f(i) == y)
			cout << i % 11 << endl;
	return 0;
}