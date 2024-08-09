#include <iostream>
#include <algorithm>
using namespace std;
const int N=5000+3;
struct node {
	int l, r;
	friend bool operator<(node x, node y) {
		if (x.l != y.l) return x.l < y.l;
		return x.r < y.r;
	}
} a[N];
int f[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
	sort(a + 1, a + 1 + n);
	int ans=0;
	f[1]=1;
	for (int i = 2; i <= n; i++) {
		f[i]=1;
		for (int j = 1; j < i; j++) {
			if (a[j].r > a[i].r) {
				f[i] = max(f[j] + 1, f[i]);
			}
		}
		ans = max(f[i], ans);
	}
	cout << ans;
	return 0;
}