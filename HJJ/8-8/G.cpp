#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
const ll N = 10010;
int n, k, q = 1;
ll b[N], f[N]; //f[i]表示1到i个时间最大空闲值。

struct node {
	ll p, t;
	friend bool operator<(node a, node b) {
		return a.p > b.p;
	}
} a[N];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		cin >> a[i].p >> a[i].t, b[a[i].p]++;
	sort(a + 1, a + k + 1);
	for (int i = n; i > 0; i--) {
		if (!b[i]) f[i] = f[i + 1] + 1;
		else {
			for (ll j = 1; j <= b[i]; j++) {
				f[i] = max(f[i], f[i+a[q].t]);
				q++;
			}
		}
	}
	cout<<f[1];
	return 0;
}