#include <iostream>
#define int long long
using namespace std;
int n, m, k;
bool check(int x) {
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += min(m, x / i);
	return sum >= k;
}
signed main() {
	cin >> n >> m >> k;
	int l = 1, r = n * m, ans = l;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else {
			ans = mid + 1;
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}