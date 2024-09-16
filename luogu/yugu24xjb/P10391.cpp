#include <iostream>
using namespace std;
const int N = 1e5 + 3;
int n, t, h[N], ans;
int main() {
	cin >> n >> t;
	for (int i = 1; i < n; ++i) cin >> h[i];
	for (int l = 1, r = 0, sum = 0; l < n; ++l) {
		while (r < n && sum < 2 * t) sum += h[++r];
		ans = max(ans, r - l + 1);
		sum -= h[l];
	}
	cout << ans;
	return 0;
}