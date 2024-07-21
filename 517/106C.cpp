#include <iostream>
using ll = long long;
using namespace std;
ll ans;
const int N = 1e5 + 10;
int a[N];

int main() {
	int n, l = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1]) l++;
		else {
			ans += 1ll * l * (l + 1) / 2;
			l = 1;
		}
	}
	cout << ans + 1ll * l*(l + 1) / 2;
	return 0;
}