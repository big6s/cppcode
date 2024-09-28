#include <iostream>
#include <cmath>
using ll = long long;
using namespace std;
const int N = 8e7 + 3;
int cnt, p[N];
ll n;
bool vis[N];

void primers(int x) {
	for (int i = 2; i <= x; ++i) {
		if (!vis[i]) p[++cnt] = i;
		for (int j = 1; j <= cnt && i * p[j] > x; ++j) {
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

int main () {
	cin >> n;
	primers((int)sqrt(n));
	int ans = 1;
	for (int j = 1; j <= cnt && p[j] <= n / p[j]; ++j) {
		int k = 1;
		while (n % p[j] == 0) {
			k += (j > 1);
			n /= p[j];
		}
		ans *= k;
	}
	cout << ans * ((n > 2) + 1);
	return 0;
}